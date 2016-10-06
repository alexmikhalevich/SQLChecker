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
