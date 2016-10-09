#include <string>
#include <map>
#include "utility.h"

namespace UserQuery {
	enum EQueryType {
		UNKNOWN_TYPE,
		SELECT_QUERY,
		INSERT_QUERY,
		DELETE_QUERY
	};

	class CQuery {
		private:
			std::string m_query;
			BitMask m_bm;
			EQueryType m_type;
			static Utility::Keywords* m_keywords = NULL;	
		public:
			CQuery(const std::string& filename);
			CQuery(const std::string& q, const BitMask& bm, const std::string& filename);
			CQuery(const CQuery&) = delete; 
			std::string get_query() const;
			void add_word(const std::string& keyword);
	};
}
