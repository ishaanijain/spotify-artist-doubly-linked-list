# spotify-artist-doubly-linked-list

A doubly-linked list implementation in C++ for managing and querying a database of Spotify artists. Built to practice object-oriented design, memory management, and data structure fundamentals.

## Features

- **Doubly-linked list** — Full implementation with bidirectional traversal
- **Memory safe** — Proper allocation/deallocation with no memory leaks
- **CSV parsing** — Reads and parses real Spotify artist chart data
- **Query support** — Find artists by name, access by index

## Data Structure

Each node contains artist information:
- Artist ID
- Name
- Total followers
- Genres (up to 10)
- Popularity score

## API

| Method | Description |
|--------|-------------|
| `prepend(artist)` | Add to front of list |
| `append(artist)` | Add to end of list |
| `insert(index, artist)` | Insert before index |
| `at(index)` | Access artist at index |
| `removeFirst()` / `removeLast()` | Remove from ends |
| `findArtistByName(name)` | Search by artist name |
| `size()` / `is_empty()` | List info |

## Example
```cpp
ArtistList list;
list.append(Artist("0du5cEVh5yTK9QJze8zA0C", "Bruno Mars", 43236735, genres, 87));
list.append(Artist("4IWBUUAFIplrNtaOHcJPRM", "James Arthur", 10293374, genres, 80));

Artist* found = list.findArtistByName("Bruno Mars");
found->printArtist();
```

Output:
```
Artist ID: 0du5cEVh5yTK9QJze8zA0C
Artist Name: Bruno Mars
Total Followers: 43236735
Genres: dance pop, pop,
Popularity: 87
```

## Building
```bash
cd src
make
./main
```

## License

MIT
