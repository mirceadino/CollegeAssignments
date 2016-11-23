#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>

class Player {
	public:
		Player();
		Player(std::string name, std::string nationality, std::string team, int goals);
		Player(const Player& that);
		Player& operator=(const Player& that);
		~Player();
		bool isValid() const;
		std::string getName() const;
		std::string getNationality() const;
		std::string getTeam() const;
		int getGoals() const;
		bool operator==(const Player& that) const;
		std::string toString() const;
		bool operator<(const Player &that) const;

	private:
		std::string name_;
		std::string nationality_;
		std::string team_;
		int goals_;
};

#endif /* PLAYER_H_ */
