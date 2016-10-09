#include "cquery.h"

CQuery::CQuery(const std::string& filename) {
	m_type = EQueryType::UNKNOWN_TYPE;
	if(!m_keywords) m_keywords = new Keywords(filename);
}

CQuery::CQuery(const std::string& q, const BitMask& bm, const std::string& filename) {
	m_query = q;
	m_bm = m;
	if(!m_keywords) m_keywords = new Keywords(filename);
}

void CQuery::add_word(const std::string& keyword) {
	size_t pos = Utility::Keywords::get_pos(keyword);
	m_bm.append_bit(pos, true);
}

std::string CQuery::get_query() {
	return m_query;
}
