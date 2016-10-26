#ifndef COUNTRY_H_
#define COUNTRY_H_

#include <fstream>
#include <string>

class Country {
public:
	Country(std::string name = "", std::string singer = "", std::string song =
			"", int score = 0) :
			name_(name), singer_(singer), song_(song), score_(score) {
	}

	Country(const Country& that) :
			name_(that.name_), singer_(that.singer_), song_(that.song_), score_(
					that.score_) {
	}

	Country& operator=(const Country& that) {
		name_ = that.name_;
		singer_ = that.singer_;
		song_ = that.song_;
		score_ = that.score_;
		return *this;
	}

	~Country() {
	}

	const std::string getName() const {
		return name_;
	}

	void setName(const std::string& name) {
		name_ = name;
	}

	int getScore() const {
		return score_;
	}

	void setScore(int score) {
		score_ = score;
	}

	const std::string getSinger() const {
		return singer_;
	}

	void setSinger(const std::string& singer) {
		singer_ = singer;
	}

	const std::string getSong() const {
		return song_;
	}

	void setSong(const std::string& song) {
		song_ = song;
	}

	void upvote() {
		score_++;
	}

	void downvote() {
		score_--;
	}

	bool operator<(const Country& that) const {
		return score_ < that.score_;
	}

private:
	std::string name_;
	std::string singer_;
	std::string song_;
	int score_;
};

std::istream& operator>>(std::istream& in, Country& C);
std::ostream& operator<<(std::ostream& out, Country& C);

#endif /* COUNTRY_H_ */
