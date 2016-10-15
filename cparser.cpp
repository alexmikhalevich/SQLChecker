#include "cparser.h"

void CParser::_get_tokens(const std::string& input) const { 
	auto begin = input.begin();
	for(auto iter = input.begin(); iter != input.end(); ++i) {
		while(isspace(*iter) || iter != input.end()) ++iter;
		if(*iter == "{") {
			m_tokens.push("{");
			++iter;
		}
		else if(*iter == "}") {
			m_tokens.push("}");
			++iter;
		}
		else if(*iter == "[") {
			m_tokens.push("[");
			++iter;
		}
		else if(*iter == "]") {
			m_tokens.push("]");
			++iter;
		}
		else if(isalpha(*iter) || isdigit(*iter)) {
			begin = iter;
			while(isalpha(*iter) || isdigit(*iter) || iter != input.end()) ++iter; //NOTE: floats are not taken into account
			m_tokens.emplace(begin, iter);
		}
		else throw new ExSyntaxError(m_filename + ": Unknown operand " + std::string(*iter));
	}
}

bool CParser::_service(const std::string& token) const {
	return (token == "_basis_" || token == "_full_");
}

void CParser::parse() {
	ifstream in(m_filename);
	std::string tmp;
	bool opened_block = false;
	while(in >> line) _get_tokens(line);
	while(!m_tokens.empty()) {
		tmp = m_tokens.front();
		m_tokens.pop();
		if(tmp == "KEYWORDS") {
			if(m_tokens.front() != "{") throw new ExSyntaxError(m_filename + ": Missing '{' after KEYWORDS");
			m_tokens.pop();
			opened_block = true;
			std::vector<std::string> keywords;
			while(m_tokens.front() != "}" || !m_tokens.empty()) {
				keywords.push_back(m_tokens.front());
				m_tokens.pop();
			}
			if(!m_tokens.empty()) opened_block = !(m_tokens.front() == "}");
			if(opened_block) throw new ExSyntaxError(m_filename + ": Missing '}' after KEYWORDS block");
			Keywords::upload_keywords(keywords);
		}
		if(tmp == "RULE") {
			bool basis_exists = false;
			CEtalonQuery query;
			if(m_tokens.empty() || m_tokens.front() == "{") throw new ExSyntaxError(m_filename + ": Missing rule name");
			std::string rule_name = m_tokens.front();
			m_tokens.pop();
			if(m_tokens.empty() || m_tokens.front() != "{") 
				throw new ExSyntaxError(m_filename + ": Missing '{' after RULE keyword");
			m_tokens.pop();
			opened_block = true;
			if(m_tokens.empty()) throw new ExSyntaxError(m_filename + ": Unexpected end of file");
			if(m_tokens.front() == "_basis_") {
				basis_exists = true;
				m_tokens.pop();
				if(m_tokens.empty()) throw new ExSyntaxError(m_filename + ": Unexpected end of file");
				Utility::BitMask bm;
				while(!_service(m_tokens.front())) {
					if(m_tokens.front() == "[") {
						//TODO
					}
					bm.append_bit(Utility::Keywords::get_pos(m_tokens.front()), 1);
					m_tokens.pop();
					if(m_tokens.empty()) throw new ExSyntaxError(m_filename + ": Unexpected end of file");
				}
			}
			query.set_bitmask(bm);
			else if(m_tokens.front() == "_full_") {
				//TODO
			}
			if(!basis_exists) throw new ExSyntaxError(m_filename + ": Missing _basis_ in " + rule_name + " rule");
			if(!m_tokens.empty()) opened_block = !(m_tokens.front() == "}");
			if(opened_block) throw new ExSyntaxError(m_filename + ": Missing '}' after RULE block");
		}
	}
}
