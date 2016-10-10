namespace Query {
	class IEtalonQuery {
		public:
			virtual double evaluate(const std::string& input) = 0;
			virtual void set_bitmask(const BitMask& bm) = 0;
			virtual bool no_bitmask() const = 0;
	};
	
	class CInsertQuery : public IEtalonQuery {
		private:
			BitMask m_bm;	
		public:
			virtual bool no_bitmask { return m_bm.empty(); }
			virtual void set_bitmask(const BitMask& bm) { m_bm = bm; }
			virtual double evaluate(const BitMask& input) {
				//TODO: evaluation algorithm 		
			}
	};
}
