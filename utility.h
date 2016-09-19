#include <array>

namespace Utility {
	constexpr double EPS = 0.0001;
	constexpr int LEXICAL_PENALTY_PERCENTAGE = 40;
	constexpr std::array<char[], 246> keywords = { "ABS", "ABSOLUTE", "ACTION", 
		"ADA", "ADD", "ADMIN", "AFTER", "ALL", "ALLOCATE", "ALTER", "ALWAYS", "AND",
		"ANY", "ARE", "ARRAY", "AS", "ASC", "ASENSITIVE", "ASSERTION", "ASSIGNMENT", 
		"ASYMMETRIC", "AT", "ATOMIC", "ATTRIBUTE", "ATTRIBUTES", "AUTHORIZATION", 
		"auto", "AVG", "BEFORE", "BEGIN", "BERNOULLI", "BETWEEN", "BIGINT", "BIN",
		"BINARY", "BLOB", "BOOLEAN", "BOTH", "BREADTH", "BY", "C", "CALL", "CALLED", 
		"CARDINALITY", "CASCADE", "CASCADED", "CASE", "CAST", "CATALOG", "CATALOG_NAME",
		"CEIL", "CEILING", "CHAIN", "char", "CHAR", "CHARACTER", "CHARACTERISTICS",
		"CHARACTERS", "CHARACTER_LENGTH", "CHARACTER_SET_CATALOG", "CHARACTER_SET_NAME",
		"CHARACTER_SET_SCHEMA", "CHAR_LENGTH", "CHECK", "CHECKED", "CLASS_ORIGIN", 
		"CLOB", "CLOSE", "COALESCE", "COBOL", "CODE_UNITS", "COLLATE", "COLLATION", 
		"COLLATION_CATALOG", "COLLATION_NAME", "COLLATION_SCHEMA", "COLLECT", 
		"COLUMN", "COLUMN_NAME", "COMMAND_FUNCTION", "COMMAND_FUNCTION_CODE", "COMMIT",
		"COMMITED", "CONDITION", "CONDITION_NUMBER", "CONNECT", "CONNECTION", "const", 
		"CONNECTION_NAME", "CONSTRAINT", "CONSTRAINTS", "CONSTRAINT_CATALOG", 
		"CONSTRAINT_NAME", "CONSTRAINT_SCHEMA", "CONSTRUCTOR", "CONSTRUCTORS", "CONTAINS",
		"CONTINUE", "CONVERT", "CORR", "CORRESPONDING", "COUNT", "COVAR_POP", "COVAR_SAMP",
		"CREATE", "CROSS", "CUBE", "CUME_DIST", "CURRENT", "CURRENT_COLLATION", 
		"CURRENT_DATE", "CURRENT_DEFAULT_TRANSFORM_GROUP", "CURRENT_PATH", "CURRENT_ROLE",
		"CURRENT_TIME", "CURRENT_TIMESTAMP", "CURRENT_TRANSFORM_GROUP_FOR_TYPE", 
		"CURRENT_USER", "CURSOR", "CURSOR_NAME", "CYCLE", "DATA", "DATE", 
		"DATETIME_INTERVAL_CODE", "DATETIME_INTERVAL_PRECISION", "DAY", "DCL", "DEALLOCATE",
		"DEC", "DECIMAL", "DECLARE", "DEFAULT", "DEFAULTS", "DEFERRABLE", "DEFERRED", 
		"DEFINED", "DEFINER", "DEGREE", "DELETE", "DENSE_RANK", "DEPTH", "DEREF", "DERIVED",
		"DESC", "DESCRIBE", "DESCRIPTOR", "DETERMINISTIC", "DIAGNOSTICS", "DISCONNECT", 
		"DISPATCH", "DISPLAY", "DISTINCT", "DOMAIN", "double", "DOUBLE", "DOUBLE_PRECISION",
		"DROP", "DYNAMIC", "DYNAMIC_FUNCTION", "DYNAMIC_FUNCTION_CODE", "EACH", "ELEMENT", 
		"ELSE", "END", "END-EXEC", "EQUALS", "ESCAPE", "EVERY", "EXCEPT", "EXCEPTION", 
		"EXCLUDE", "EXCLUDING", "EXEC", "EXECUTE", "EXISTS", "EXTERNAL", "FALSE", "FETCH", 
		"FILTER", "FLOAT", "FOR", "FOREIGN", "FREE", "FROM", "FULL", "FUNCTION", "GET", "GLOBAL", 
		"GRANT", "GROUP", "GROUPING", "HAVING", "HOLD", "HOUR", "IDENTITY", "IMMEDIATE", "IN", 
		"INDICATOR", "INNER", "INOUT", "INPUT", "INSENSITIVE", "INSERT", "INT", "INTEGER", 
		"INTERSECT", "INTERVAL", "INTO", "IS", "ISOLATION", "JOIN", "LANGUAGE", "LARGE", 
		"LATERAL", "LEADING", "LEFT", "LIKE", "LOCAL", "LOCALTIME", "LOCALTIMESTAMP", "MATCH", 
		"MEMBER", "MERGE", "METHOD", "MINUTE", "MODIFIES", "MODULE", "MONTH", "MULTISET", 
		"NATIONAL", "NATURAL", "NCHAR", "NCLOB", "NEW", "NO", "NONE", "NOT", "NULL", "NUMERIC", 
		"OF", "OLD", "ON", "ONLY", "OPEN", "OR", "ORDER", "OUT", "OUTER", "OUTPUT", "OVER", 
		"OVERLAPS", "PARAMETER", "PARTITION", "PRECISION", "PREPARE", "PRIMARY", "PROCEDURE", 
		"RANGE", "READS", "REAL", "RECURSIVE", "REF", "REFERENCES", "REFERENCING", "REGR_AVGX", 
		"REGR_AVGY", "REGR_COUNT", "REGR_INTERCEPT", "REGR_R2", "REGR_SLOPE", "REGR_SXX", 
		"REGR_SXY", "REGR_SYY", "RELEASE", "RESULT", "RETURN", "RETURNS", "REVOKE", "RIGHT", 
		"ROLLBACK", "ROLLUP", "ROW", "ROWS", "SAVEPOINT", "SCROLL", "SEARCH", "SECOND", "SELECT", 
		"SENSITIVE", "SESSION_USER", "SET", "SIMILAR", "SMALLINT", "SOME", "SPECIFIC", 
		"SPECIFICTYPE", "SQL", "SQLEXCEPTION", "SQLSTATE", "SQLWARNING", "START", "STATIC", 
		"SUBMULTISET", "SYMMETRIC", "SYSTEM", "SYSTEM_USER", "TABLE", "THEN", "TIME", "TIMESTAMP", 
		"TIMEZONE_HOUR", "TIMEZONE_MINUTE", "TO", "TRAILING", "TRANSLATION", "TREAT", "TRIGGER", 
		"TRUE", "UESCAPE", "UNION", "UNIQUE", "UNKNOWN", "UNNEST", "UPDATE", "UPPER", "USER", 
		"USING", "VALUE", "VALUES", "VAR_POP", "VAR_SAMP", "VARCHAR", "VARYING", "WHEN", 
		"WHENEVER", "WHERE", "WIDTH_BUCKET", "WINDOW", "WITH", "WITHIN", "WITHOUT", "YEAR" };
};
