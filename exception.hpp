class IException {
	public:
		virtual std::string what() const = 0;
};

class ExInvalidArguments {
	private:
		std::string m_location;
	public:
		ExInvalidArguments(const std::string& location) : m_location(location) {}
		std::string what() const {
			return "[EE]: " + m_location + ": Invalid arguments";
		}
};

class ExOutOfRange {
	private:
		std::string m_location;
	public:
		ExOutOfRange(const std::string& location) : m_location(location) {}
		std::string what() const {
			return "[EE]: " + m_location + ": Out of range";
		}
};

class ExNoBitmask {
	private:
		std::string m_location;
	public:
		ExNoBitmask(const std::string& location) : m_location(location) {}
		std::string what() const {
			return "[EE]: " + m_location + ": No bitmask was provided";
		}
};

class ExTypeNotFound {
	private:
		std::string m_location;
	public:
		ExTypeNotFound(const std::string& location) : m_location(location) {}
		std::string what() const {
			return "[EE]: " + m_location + ": Unknown type";
		}
};

class ExSyntaxError {
	private:
		std::string m_location;
	public:
		ExSyntaxError(const std::string& location) : m_location(location) {}
		std::string what() const {
			return "[EE]: Syntax error in " + m_location;
		}
};
