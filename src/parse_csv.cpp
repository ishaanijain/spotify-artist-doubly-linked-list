#include <artistList.hpp>
#include <istream>
#include <iostream>
#include <sstream>
#include <string>

static void parse_genres(std::istream & file, std::string genres[Artist::max_genres]) {
    std::string temp;

    std::getline(file, temp, '[');
    std::getline(file, temp, ']');

    auto genre_idx = 0u;
    for(auto start = 0u; start < temp.size() and genre_idx < Artist::max_genres; ){
        auto start_quote = temp.find_first_of('\'', start) + 1;
        auto end_quote = temp.find_first_of('\'', start_quote);
        
        genres[genre_idx] = temp.substr(start_quote, end_quote - start_quote);
        ++genre_idx;

        start = end_quote + 1;
    }
    
    while(genre_idx < Artist::max_genres){
        genres[genre_idx] = "";
        ++genre_idx;
    }
}

static std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, last - first + 1);
}

ArtistList parse_csv(std::istream& file) {
   ArtistList list;
   std::string line;
   
   std::getline(file, line);
   
   while (std::getline(file, line)) {
     if (line.empty()) continue;
     
     try {
       std::istringstream lineStream(line);
       
       std::string artist_id;
       std::getline(lineStream, artist_id, ',');
       artist_id = trim(artist_id);
       
       std::string artist_name;
       std::getline(lineStream, artist_name, ',');
       artist_name = trim(artist_name);
       
       std::string followers_str;
       std::getline(lineStream, followers_str, ',');
       followers_str = trim(followers_str);
       if (followers_str.empty()) continue;
       int total_followers = std::stoi(followers_str);
       
       
       while (lineStream.peek() == ' ') {
         lineStream.get();
       }
       
       char nextChar = lineStream.peek();
       if (nextChar == '"') {
         // Genres is quoted, consume the quote
         lineStream.get();
       }
       
       std::string genres[Artist::max_genres];
       parse_genres(lineStream, genres);
       
       if (nextChar == '"') {
         lineStream.get(); 
         if (lineStream.peek() == ',') {
           lineStream.get(); 
         }
       } else {
         if (lineStream.peek() == ',') {
           lineStream.get(); 
         }
       }
       
       while (lineStream.peek() == ' ' && lineStream.good()) {
         lineStream.get();
       }
       
       std::string popularity_str;
       std::getline(lineStream, popularity_str);
       popularity_str = trim(popularity_str);
       if (popularity_str.empty()) continue;
       int popularity = std::stoi(popularity_str);
       
       Artist artist(artist_id, artist_name, total_followers, genres, popularity);
       list.appendArtist(artist);
     } catch (...) {
       continue;
     }
   }
   
   return list;
}