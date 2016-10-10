#include "query.hpp"
#include "cparser.hpp"

namespace Analyzer {
	class CGrammar { 
		private;
			CUserQuery m_query;
			CParser m_parser;
			std::map<Query::EQueryType, IEtalonQuery*> m_query_types;
		public:
			CGrammar() = delete;
			CGrammar(const CParser& parser) : m_parser(parser) {}
			void register_type(Query::EQueryType query_type, IEtalonQuery* query_class) {
				m_query_types.insert(std::pair<EQueryType, IEtalonQuery*>(query_type, query_class));
			}
			double evaluate(const Query::CUserQuery& query) {
				IEtalonQuery* etalon = m_query_types.find(query.get_type()); //TODO: type_not_found exception
				return etalon->evaluate(query);	//TODO: maybe normalization is necessary
			}

	};
}
