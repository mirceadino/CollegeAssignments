#ifndef STLMAPWRAPPER_H_
#define STLMAPWRAPPER_H_

#include <map>
#include <vector>
#include "Pair.h"

template<typename TKey, typename TValue>
class STLMapWrapper {

	public:

		STLMapWrapper() {
			elements_ = std::map<TKey, TValue>();
		}

		STLMapWrapper(const STLMapWrapper<TKey, TValue>& that) {
			elements_ = that.elements_;
		}

		STLMapWrapper<TKey, TValue>& operator=(const STLMapWrapper<TKey, TValue>& that) {
			elements_ = that.elements_;
			return *this;
		}

		~STLMapWrapper() {
		}

		bool empty() const {
			return elements_.empty();
		}

		int size() const {
			return elements_.size();
		}

		void clear() {
			elements_.clear();
		}

		bool containsKey(const TKey key) const {
			return elements_.count(key);
		}

		TValue getValue(const TKey key) const {
			return elements_[key];
		}

		void setValue(const TKey key, const TValue value) {
			elements_[key] = value;
		}

		TValue& operator[](const TKey key) {
			return elements_[key];
		}

		TValue& at(const TKey key) {
			return elements_[key];
		}

		void insert(const TKey key, const TValue value) {
			elements_[key] = value;
		}

		void erase(const TKey key) {
			if (elements_.count(key))
				elements_.erase(key);
		}

	private:
		std::map<TKey, TValue> elements_;
};

#endif /* STLMAPWRAPPER_H_ */
