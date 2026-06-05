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
int main()
{
  std::map<std::string,float> db = data_to_map();
  for (std::map<std::string, float>::iterator it = db.begin(); it != db.end(); ++it)
  {
     std::cout << it->first << " -> " << std::fixed << std::setprecision(2) <<it->second << std::endl;
  }
    return(0);
}