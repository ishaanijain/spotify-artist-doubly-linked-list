
#include "../include/artistList.hpp"
#include <iostream>

Artist::Artist(const std::string & artist_id, const std::string & artist_name, int total_followers, std::string genres[Artist::max_genres], int popularity) 
  : artist_id(artist_id), artist_name(artist_name), total_followers(total_followers), popularity(popularity) {
  if (genres != nullptr) {
    for (std::size_t i = 0; i < max_genres; ++i) {
      this->genres[i] = genres[i];
    }
  } else {
    for (std::size_t i = 0; i < max_genres; ++i) {
      this->genres[i] = "";
    }
  }
}

void Artist::printArtist() const {
  std::cout << "Artist ID: " << artist_id << std::endl;
  std::cout << "Artist Name: " << artist_name << std::endl;
  std::cout << "Total Followers: " << total_followers << std::endl;
  std::cout << "Genres: ";
  for (std::size_t i = 0; i < max_genres; ++i) {
    if (!genres[i].empty()) {
      std::cout << genres[i] << ",";

      bool hasMore = false;
      for (std::size_t j = i + 1; j < max_genres; ++j) {
        if (!genres[j].empty()) {
          hasMore = true;
          break;
        }
      }
      if (hasMore) {
        std::cout << " ";
      }
    }
  }
  std::cout << std::endl;
  std::cout << "Popularity: " << popularity << std::endl;
}

const std::string& Artist::name() const {
  return artist_name;
}

const std::string& Artist::id() const {
  return artist_id;
}