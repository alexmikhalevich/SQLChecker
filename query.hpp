#include <string>
#include <map>
#include "utility.h"

namespace Query {
	enum EQueryType {
		UNKNOWN_TYPE,
		SELECT_QUERY,
		INSERT_QUERY,
		DELETE_QUERY
	};

	class CUserQuery {
		private:
			std::string m_query;
			BitMask m_bm;
			EQueryType m_type;
			static Utility::Keywords* m_keywords = NULL;	
		public:
			CUserQuery(const std::string& query, Utility::Keywords* keywords) 
				: m_query(query), m_type(EQueryType::UNKNOWN_TYPE) {
				if(!m_keywords) m_keywords = keywords;
			}
			CUserQuery(const CQuery&) = delete; 
			~CUserQuery() { 
				if(m_keywords) delete m_keywords;
			}
			std::string get_query() const { return m_query; }
			void add_word(const std::string& keyword) {
				size_t pos = Utility::Keywords::get_pos(keyword);
				m_bm.append_bit(pos, true);
			}
			EQueryType get_type() const { return m_type; }
	};
}
