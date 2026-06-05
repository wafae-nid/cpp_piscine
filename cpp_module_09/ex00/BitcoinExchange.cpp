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
bool BitcoinExchange::is_valid_date(std::string date)
{
    size_t pos_1;
    pos_1 = date.find('-');
    if(pos_1 == std::string::npos)
        return(0);
    std::string year_str = date.substr(0,pos_1);
    std::cout << year_str << std::endl;
    size_t pos_2;
    pos_2 = (date.substr(pos_1 + 1)).find('-');
    if(pos_2 == std::string::npos)
        return(0);
    std::string month_str = date.substr(pos_1 + 1 , pos_2);
    std::cout << month_str << std::endl;
    std::string day_str = date.substr(pos_2 + 1+ pos_1 + 1);
    std::cout <<day_str << std::endl;
    return(1);
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
    if(!is_valid_date(date))
    {
        std::cout<< "Error: bad input => "<< date<< std::endl;
    }
    std::string val_str = line.substr(pipe+1);

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
