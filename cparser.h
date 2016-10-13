#include <fstream>
#include <string>
#include <list>
#include <queue>
#include "utility.h"

class CParser {
	private:
		std::string m_filename;
		std::queue<std::string> m_tokens;
		void _get_tokens(const std::string&) const;
	public:
		CParser(const std::string& filename) : m_filename(filename) {}
		CParser() = delete;
		CParser(const CParser&) = delete;
		void parse();
};
