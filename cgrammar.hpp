#include "query.hpp"
#include "cparser.hpp"
#include "etalonquery.hpp"

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
				if(query_class->no_bitmask()) throw new ExNoBitmask("cgrammar.hpp: register_type()");
				m_query_types.insert(std::pair<EQueryType, IEtalonQuery*>(query_type, query_class));
			}
			double evaluate(const Query::CUserQuery& query) {
				std::map<Query::EQueryType, IEtalonQuery*>::iterator iter = m_query_types.find(query.get_type());
				if(iter == m_query_types.end()) throw new ExTypeNotFound("cgrammar.hpp: evaluate()");
				return iter->second->evaluate(query);	//TODO: maybe normalization is necessary
			}

	};
}
