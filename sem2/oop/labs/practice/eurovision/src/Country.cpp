#include "Country.h"

std::istream& operator>>(std::istream& in, Country& C) {
	std::string name, singer, song;
	std::string separator = "|", buffer;
	int score;

	if (!(in >> buffer))
		return in;
	while (buffer != separator) {
		name += buffer + " ";
		in >> buffer;
	}
	if (!name.empty())
		name.erase(name.end() - 1);

	in >> buffer;
	while (buffer != separator) {
		singer += buffer + " ";
		in >> buffer;
	}
	if (!singer.empty())
		singer.erase(singer.end() - 1);

	in >> buffer;
	while (buffer != separator) {
		song += buffer + " ";
		in >> buffer;
	}
	if (!song.empty())
		song.erase(song.end() - 1);

	in >> score;

	C.setName(name);
	C.setSinger(singer);
	C.setSong(song);
	C.setScore(score);

	return in;
}

std::ostream& operator<<(std::ostream& out, Country& C) {
	out << C.getName() << " | ";
	out << C.getSinger() << " | ";
	out << C.getSong() << " | ";
	out << C.getScore() << "\n";

	return out;
}
