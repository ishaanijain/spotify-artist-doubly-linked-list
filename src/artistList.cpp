
#include "../include/artistList.hpp"
#include <iostream>

ArtistList::ArtistEntry::ArtistEntry(ArtistList* list, const Artist& a) 
  : list(list), next(nullptr), prev(nullptr), artist(a) {
}

ArtistList::ArtistList() : length(0), first(nullptr), last(nullptr) {
}

std::size_t ArtistList::size() const {
  return length;
}

bool ArtistList::is_empty() const {
  return length == 0;
}

ArtistList::ArtistList(const ArtistList & list) : length(0), first(nullptr), last(nullptr) {
  ArtistEntry* current = list.first;
  while (current != nullptr) {
    appendArtist(current->artist);
    current = current->next;
  }
}

ArtistList::~ArtistList() noexcept {
  ArtistEntry* current = first;
  while (current != nullptr) {
    ArtistEntry* next = current->next;
    delete current;
    current = next;
  }
}

void ArtistList::prependArtist(const Artist& a) {
  ArtistEntry* newEntry = new ArtistEntry(this, a);
  
  if (is_empty()) {
    first = last = newEntry;
  } else {
    newEntry->next = first;
    first->prev = newEntry;
    first = newEntry;
  }
  ++length;
}

void ArtistList::appendArtist(const Artist& a) {
  ArtistEntry* newEntry = new ArtistEntry(this, a);
  
  if (is_empty()) {
    first = last = newEntry;
  } else {
    newEntry->prev = last;
    last->next = newEntry;
    last = newEntry;
  }
  ++length;
}

void ArtistList::removeFirstArtist() {
  if (is_empty()) {
    return;
  }
  
  ArtistEntry* toRemove = first;
  
  if (first == last) {
    // Only one element
    first = last = nullptr;
  } else {
    first = first->next;
    first->prev = nullptr;
  }
  
  delete toRemove;
  --length;
}

void ArtistList::removeLastArtist() {
  if (is_empty()) {
    return;
  }
  
  ArtistEntry* toRemove = last;
  
  if (first == last) {
    first = last = nullptr;
  } else {
    last = last->prev;
    last->next = nullptr;
  }
  
  delete toRemove;
  --length;
}

void ArtistList::printArtistList() const {
  ArtistEntry* current = first;
  while (current != nullptr) {
    current->artist.printArtist();
    std::cout << std::endl;
    current = current->next;
  }
}

Artist *ArtistList::findArtistName(const std::string& name) const {
  ArtistEntry* current = first;
  while (current != nullptr) {
    if (current->artist.name() == name) {
      return &(current->artist);
    }
    current = current->next;
  }
  return nullptr;
}


void ArtistList::removeArtistbyName(const std::string & name) {
  ArtistEntry* current = first;
  
  while (current != nullptr) {
    if (current->artist.name() == name) {
      if (current == first && current == last) {

        first = last = nullptr;
      } else if (current == first) {

        first = current->next;
        first->prev = nullptr;
      } else if (current == last) {

        last = current->prev;
        last->next = nullptr;
      } else {

        current->prev->next = current->next;
        current->next->prev = current->prev;
      }
      
      delete current;
      --length;
      return;
    }
    current = current->next;
  }
}

void ArtistList::insertArtistAt(std::size_t index, const Artist& artist) {

  if (index == 0) {
    prependArtist(artist);
    return;
  }
  
  if (index == length) {
    appendArtist(artist);
    return;
  }
  
  if (index > length) {
    return;
  }
  
  ArtistEntry* current = first;
  for (std::size_t i = 0; i < index; ++i) {
    current = current->next;
  }
  
  ArtistEntry* newEntry = new ArtistEntry(this, artist);
  newEntry->next = current;
  newEntry->prev = current->prev;
  
  if (current->prev != nullptr) {
    current->prev->next = newEntry;
  } else {
    first = newEntry; 
  }
  current->prev = newEntry;
  
  ++length;
}

Artist * ArtistList::at(size_t index) {
  if (index >= length) {
    return nullptr;
  }
  
  ArtistEntry* current = first;
  for (std::size_t i = 0; i < index; ++i) {
    current = current->next;
  }
  
  return &(current->artist);
}

const Artist * ArtistList::at(size_t index) const {
  if (index >= length) {
    return nullptr;
  }
  
  ArtistEntry* current = first;
  for (std::size_t i = 0; i < index; ++i) {
    current = current->next;
  }
  
  return &(current->artist);
}

Artist* ArtistList::firstArtist() {
  if (first == nullptr) {
    return nullptr;
  }
  return &(first->artist);
}

const Artist* ArtistList::firstArtist() const {
  if (first == nullptr) {
    return nullptr;
  }
  return &(first->artist);
}

Artist* ArtistList::lastArtist() {
  if (last == nullptr) {
    return nullptr;
  }
  return &(last->artist);
}

const Artist* ArtistList::lastArtist() const {
  if (last == nullptr) {
    return nullptr;
  }
  return &(last->artist);
}