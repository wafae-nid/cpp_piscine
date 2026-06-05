#include "BitcoinExchange.hpp"

std::map<std::string,float> data_to_map(void)
{
    std::string line;
    size_t comma;
    std::map<std::string, float> map_db;

    std::ifstream file("data.csv");
     if(!file)
    {
        std::cerr << "failed to open the file data.csv"  << "\n";
        return(map_db);
    }
    getline(file, line);
    while(std::getline(file,line))
    {
        comma = line.find(',');
        std::string date = line.substr(0,comma);
        std::string val_str = line.substr(comma+1);
        char *end;
        float val = strtof(val_str.c_str(),&end);
        map_db.insert(std::make_pair(date, val));
    }
    return(map_db);
}

BitcoinExchange::BitcoinExchange()
{
    map_db = data_to_map();
}

std::string BitcoinExchange::trim(const std::string& s)
{
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end   = s.find_last_not_of(" \t\r\n");
    if (start == std::string::npos)
        return "";
    return s.substr(start, end - start + 1);
}

bool BitcoinExchange::is_all_digit(std::string str) 
{
    for(size_t i = 0; i < str.size(); i++)
    {
        if(!isdigit(str[i]))
            return(false);
    }
    return(true);
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
    
    if (*end != '\0')
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
bool BitcoinExchange::is_valid_day(std::string day)
{
    if(!is_all_digit(day))
        return(false);
    else
    {
        int int_day = std::atoi(day.c_str());
        if(int_day < 0 || int_day > 31)
            return(false);
        else
            return(true);
    }
}
bool BitcoinExchange::is_valid_month(std::string month)
{
    if(!is_all_digit(month))
        return(false);
    else
    {
        int int_month = std::atoi(month.c_str());
        if(int_month < 0 || int_month > 12)
            return(false);
        else
            return(true);
    }
}

bool BitcoinExchange::is_valid_year(std::string year)
{
    if(!is_all_digit(year))
        return(false);
    else
    {
        int int_year = std::atoi(year.c_str());
        if(int_year <2009 || int_year > 2026)
            return(false);
        else
            return(true);
    }
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
    
    if(!is_valid_year(year_str))
        return(false);
    
    if(!is_valid_month(month_str))
       return(false); 
    if(!is_valid_day(day_str))
        return(false);

    return(true);
}
void BitcoinExchange::display_result(std::string date, float val)
{
    std::map<std::string,float>::iterator it;
    it =  map_db.lower_bound(date);
    float result = it->second * val;
    std::cout << date<< " => " << val << " = " << result << std::endl;

}
void BitcoinExchange::processLine(std::string line)
{
    size_t pipe ;
    pipe = line.find('|');
    if(pipe == std::string::npos)
    {
        std::cout << "Error: bad input => "<<line << std::endl;
        return;
    }
    std::string date = line.substr(0,pipe);
    std::string trimmed_date = trim(date);

    if(trimmed_date.empty() || !is_valid_date(trimmed_date))
    {
        std::cout<< "Error: bad input => "<< date<< std::endl;
    }
    std::string val_str = trim(line.substr(pipe + 1));
    bool valid;
    float val = parse_value(val_str, valid);
    if (!valid)
        return;
    display_result(date, val);
}
void BitcoinExchange::data_search(std::ifstream& input)
{
    std::string line;

    getline(input, line);
    while(std::getline(input,line))
    {
        processLine(line);
    }

}
void BitcoinExchange::processInput(const std::string& file)
{

    std::ifstream input(file.c_str());
    if(!input)
    {
        std::cout << "Error: could not open file.\n";
        return;
    }
    data_search(input);

}
BitcoinExchange::~BitcoinExchange()
{

}
