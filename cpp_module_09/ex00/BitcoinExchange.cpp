
#include "BitcoinExchange.hpp"

std::map<std::string, float> data_to_map(void)
{
    std::string line;
    size_t comma;
    std::map<std::string, float> map_db;

    std::ifstream file("data.csv");
    if (!file)
    {
        std::cerr << "Error: failed to open data.csv" << std::endl;
        return map_db;
    }

    std::getline(file, line);

    while (std::getline(file, line))
    {
        if (!line.empty() && line[line.size() - 1] == '\r')
            line.erase(line.size() - 1);

        comma = line.find(',');
        if (comma == std::string::npos)
        {
            std::cerr << "Error: invalid line in data.csv: "
                      << line << std::endl;
            return std::map<std::string, float>();
        }

        std::string date = line.substr(0, comma);
        std::string val_str = line.substr(comma + 1);

        char *end;
        float val = std::strtof(val_str.c_str(), &end);

        if (end == val_str.c_str() || *end != '\0')
        {
            std::cerr << "Error: invalid exchange rate in data.csv: "
                      << val_str << std::endl;
            return std::map<std::string, float>();
        }

        if (val < 0)
        {
            std::cerr << "Error: negative exchange rate in data.csv: "
                      << val_str << std::endl;
            return std::map<std::string, float>();
        }

        map_db.insert(std::make_pair(date, val));
    }
    return map_db;
}

BitcoinExchange::BitcoinExchange()
{
    map_db = data_to_map();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : map_db(other.map_db)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        map_db = other.map_db;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

bool BitcoinExchange::is_all_digit(std::string str)
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!isdigit(static_cast<unsigned char>(str[i])))
            return false;
    }
    return true;
}

float BitcoinExchange::parse_value(const std::string& val_str, bool& valid)
{
    if (val_str.empty())
    {
        valid = false;
        return 0;
    }
    char *end;
    float val = strtof(val_str.c_str(), &end);

    if (end == val_str.c_str() || *end != '\0' || val != val)
    {
        std::cout << "Error: bad input => " << val_str << std::endl;
        valid = false;
        return 0;
    }
    if (val < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        valid = false;
        return 0;
    }
    if (val > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        valid = false;
        return 0;
    }
    valid = true;
    return val;
}
bool BitcoinExchange::is_valid_day(std::string day, int month, int year)
{
    if (!is_all_digit(day))
        return false;

    int int_day = std::atoi(day.c_str());
    int max_day;

    if (month == 2)
    {
        if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
            max_day = 29;
        else
            max_day = 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        max_day = 30;
    else
        max_day = 31;

    if (int_day < 1 || int_day > max_day)
        return false;

    return true;
}

int BitcoinExchange::is_valid_month(std::string month)
{
    if (!is_all_digit(month))
        return -1;

    int int_month = std::atoi(month.c_str());
    if (int_month < 1 || int_month > 12)
        return -1;
    return int_month;
}

int BitcoinExchange::is_valid_year(std::string year)
{
    if (!is_all_digit(year))
        return -1;

    int int_year = std::atoi(year.c_str());
    if (int_year < 1)
        return -1;
    return int_year;
}

bool BitcoinExchange::is_valid_date(std::string date)
{
    size_t pos_1 = date.find('-');
    if (pos_1 == std::string::npos)
        return false;

    size_t pos_2 = date.find('-', pos_1 + 1);
    if (pos_2 == std::string::npos)
        return false;

    std::string year_str = date.substr(0, pos_1);
    std::string month_str = date.substr(pos_1 + 1, pos_2 - pos_1 - 1);
    std::string day_str = date.substr(pos_2 + 1);

    // Enforce YYYY-MM-DD so string comparison in the map stays correct
    // and atoi can't overflow on huge digit strings.
    if (year_str.length() != 4 || month_str.length() != 2 || day_str.length() != 2)
        return false;

    int year = is_valid_year(year_str);
    if (year == -1)
        return false;
    int month = is_valid_month(month_str);
    if (month == -1)
        return false;
    if (!is_valid_day(day_str, month, year))
        return false;
    return true;
}

void BitcoinExchange::display_result(const std::string& date, float val)
{
    std::map<std::string, float>::iterator it = map_db.upper_bound(date);
    if (it == map_db.begin())
    {
        std::cout << "Error: no earlier date in database." << std::endl;
        return;
    }
    --it;
    std::cout << date << " => " << val << " = " << it->second * val << std::endl;
}

void BitcoinExchange::processLine(std::string line)
{
    size_t pipe = line.find('|');
    if (pipe == std::string::npos)
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return;
    }

    std::string date = line.substr(0, pipe);
    size_t space = date.find(' ');
    if (space == std::string::npos || date.substr(space).length() != 1)
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return;
    }

    std::string after_pipe = line.substr(pipe + 1);
    size_t pos = after_pipe.find_first_not_of(' ');
    if (pos == std::string::npos || after_pipe.substr(0, pos).length() != 1)
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return;
    }

    std::string trimmed_date = date.substr(0, space);
    if (!is_valid_date(trimmed_date))
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return;
    }

    std::string val_str = after_pipe.substr(pos);
    bool valid;
    float val = parse_value(val_str, valid);
    if (!valid)
        return;
    display_result(trimmed_date, val);
}

void BitcoinExchange::data_search(std::ifstream& input)
{
    std::string line;

    std::getline(input, line);
    while (std::getline(input, line))
    {
        if (!line.empty() && line[line.size() - 1] == '\r')
            line.erase(line.size() - 1);

        processLine(line);
    }
}

void BitcoinExchange::processInput(const std::string& file)
{
    if (map_db.empty())
    {
        std::cerr << "Error: database has error" << std::endl;
        return;
    }
    std::ifstream input(file.c_str());
    if (!input)
    {
        std::cout << "Error: could not open file." << std::endl;
        return;
    }
    data_search(input);
}