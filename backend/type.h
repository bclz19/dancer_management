#ifndef __TYPE__
#define __TYPE__

#include <iostream>
#include <string>
using std::string;
#include <vector>
using std::vector;

class type{
    private:
        string path;
        int num;
        vector<string> asset_list;
    public:
        type(string path, int num): path(path), num(num) {};
        string get_path() const {
            return path;
        }
        void change_path(string new_path) {
            path = new_path;
        }
        int get_num() const {
            return num;
        }
        void change_num(int new_num) {
            num = new_num;
        }
        vector<string> get_asset_list() const {
            return asset_list;
        }
        void add_asset(string asset_name) {
            asset_list.push_back(asset_name);
        }
        void load_asset_list(const vector<string>& new_asset_list) {
            asset_list = new_asset_list;
        }
        void save_to_file(std::ostream& out) const {
            out << path << std::endl;
            out << num << std::endl;
            out << asset_list.size() << std::endl;
            for (const auto& asset : asset_list) {
                out << asset << std::endl;
            }
        }
};

#endif