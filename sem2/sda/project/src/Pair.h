#ifndef PAIR_H_
#define PAIR_H_

template<typename TFirst, typename TSecond>
struct Pair {
		TFirst first;
		TSecond second;

		Pair(TFirst _first, TSecond _second) :
				first(_first), second(_second) {
		}

		bool operator<(const Pair<TFirst, TSecond>& that) const {
			return first < that.first;
		}

		bool operator>(const Pair<TFirst, TSecond>& that) const {
			return first > that.first;
		}

		bool operator==(const Pair<TFirst, TSecond>& that) const {
			return first == that.first;
		}
};

#endif /* PAIR_H_ */
