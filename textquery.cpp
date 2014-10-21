#include <iostream>
#include <stdexcept>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class TextQuery{

public:
    typedef vector<string>::size_type line_no;
    void read_file(ifstream &is){
        store_file(is);
        build_map();
    }
    set<line_no> run_query(const string &) const;
    string text_line(line_no) const;

private:
    void store_file(ifstream &is);
    void build_map();
    vector<string> lines_of_text;
    map<string, set<line_no> > word_map;
};

void TextQuery::store_file(ifstream &is){
    string textline;
    while(getline(is, textline)){
        lines_of_text.push_back(textline);
    }
}

void TextQuery::build_map(){
    for(line_no line_num=0; line_num!=lines_of_text.size(); ++line_num){
        istringstream line(lines_of_text[line_num]);
        string word;
        while(line>>word){
            word_map[word].insert(line_num);
        }
    }
}

set<TextQuery::line_no> TextQuery::run_query(const string &query_word) const{
    map<string, set<line_no> >::const_iterator loc = word_map.find(query_word);
    if(loc == word_map.end()){
        return set<line_no>();
    }else{
        return loc->second;
    }
}

string TextQuery::text_line(line_no line) const{
    if(line < lines_of_text.size()){
        return lines_of_text[line];
    }else{
        throw out_of_range("line number out of range");
    }
}

string make_plural(size_t str, const string &word, const string &ending){
    return (str == 1) ? word : word+ending;
}


void print_results(const set<TextQuery::line_no>& locs, const string& sought, const TextQuery &file){
    typedef set<TextQuery::line_no> line_nums;
    line_nums::size_type size = locs.size();
    cout<<"\n"<<sought<<" occurs "<<size<<" "<<make_plural(size, "time", "s") <<endl;

    line_nums::const_iterator it = locs.begin();
    for(; it!=locs.end(); ++it){
        cout<<"\t(line "<<(*it)+1<<") "<<file.text_line(*it) <<endl;
    }
}

ifstream& open_file(ifstream &in, const string &file){
    in.close();
    in.clear();
    in.open(file.c_str());
    return in;
}


int main(int argc, char *argv[]){
    
    ifstream infile;
    if(argc<2 || !open_file(infile, argv[1])){
        cerr<<"No input file!"<<endl;
        return -1;
    }

    TextQuery tq;
    tq.read_file(infile);

    while(true){
        cout<<"\nenter word to look for, or q to quit: ";
        string s;
        cin >> s;

        if(!cin || s == "q") break;

        set<TextQuery::line_no> locs = tq.run_query(s);
        print_results(locs, s, tq);
    }

    return 0;
}
