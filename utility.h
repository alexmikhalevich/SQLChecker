#include <array>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <fstream>
#include "clog.h"
#include "exception.hpp"

namespace Utility {
	constexpr double EPS = 0.0001;
	constexpr double LEXICAL_PENALTY_PERCENTAGE = 40.0;
	constexpr double GRAMMAR_PENALTY_PERCENTAGE = 100.0 - LEXICAL_PENALTY_PERCENTAGE;
	
	/*template<class T>
	class CSingleton {
		private:
			static T* m_object = NULL;
		public:
			CSingleton() = delete;
			~CSingleton() = delete;
			CSingleton(const CSingleton&) = delete;
			CSingleton operator= (const CSingleton&) = delete;
			static T* get_instance() {
				if(!m_object) m_object = new T; //TODO 
				return m_object;
			}
	};*/

	class BitMask {
		private:
			std::array<bool, Keywords::amount()> m_mask;
		public:
			BitMask() {}
			BitMask(const std::array<bool, Keywords::amount()>& mask) : m_mask(mask) {}
			void append_bit(size_t pos, bool bit) {
				if(pos >= Keywords::amount()) throw new ExOutOfRange("utility.h: append_bit()");
				m_mask[pos] = bit; 
			}
			bool empty() const { return m_mask.empty(); }
			BitMask operator& (const BitMask& a, const BitMask& b) {
				BitMask bm;
				for(size_t i = 0; i < Keywords::amount(); ++i) bm.m_mask[i] = a.m_mask[i] & b.m_mask[i];
				return bm;
			}
			BitMask operator| (const BitMask& a, const BitMask& b) {
				BitMask bm;
				for(size_t i = 0; i < Keywords::amount(); ++i) bm.m_mask[i] = a.m_mask[i] | b.m_mask[i];
				return bm;
			}
	};

	class Keywords {
		private:
			static std::map<std::string, size_t> m_keywords;
		public:
			Keywords();
			size_t amount() const { return m_keywords.size(); }
			size_t get_pos(const std::string& keyword) const {
				return m_keywords.find(keywords)->second;
			}
			static void upload_keywords(std::vector<std::string>& keywords) {
				if(!m_keywords.empty()) m_keywords.clear();
				std::sort(keywords.begin(), keywords.end(), std::less<std::string>());
				for(size_t i = 0; i < keywords.size(); ++i) {
					m_keywords.insert(std::pair<std::string, size_t>(keywords[i], i));
			}
	};
};
