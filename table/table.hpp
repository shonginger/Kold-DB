#ifndef KOLD_DB_TABLE_HPP
#define KOLD_DB_TABLE_HPP

#include <iosfwd>

#include "format.hpp"
#include "key_value.hpp"

class Table
{
private:
        std::fstream& _file;
        IKeyValueCollection<IndexItem>& _index;

public:
        Table();

        IndexItem& AddEntry(Entry& entry);
        IndexItem& AddEntry(std::string key, std::string value);

        IndexItem& DeleteEntry(Entry& entry);
        IndexItem& DeleteEntry(std::string& key);
        IndexItem& DeleteEntry(IndexItem& indexItem);

        std::string& GetEntry(const Entry& entry);
        std::string& GetEntry(const std::string& key);
        std::string& GetEntry(const IndexItem& indexItem);
};



#endif // KOLD_DB_TABLE_HPP

