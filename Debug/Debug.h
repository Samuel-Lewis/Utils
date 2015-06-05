
//====================================================//
// AUTHOR		Sam Lewis
// LASTE UPDATE	3/06/2015
// PROJECT		Utility Debug
//
// OUTLINE
//		Debug file to be used throughout the programs to log things.
//====================================================//

#ifndef DEBUG_H
#define DEBUG_H

#include <fstream>
#include <string>
#include <vector>


// Different error levels to be called through the rest of the program
#define FATAL(msg) Debug::out(__FILE__, __LINE__, "FATAL", 1, (msg));
#define ERROR(msg) Debug::out(__FILE__, __LINE__, "ERROR", 2, (msg));
#define WARN(msg) Debug::out(__FILE__, __LINE__, "WARNING",3,(msg));
#define INFO(msg) Debug::out(__FILE__, __LINE__, "INFO", 4, (msg));
#define DEBUG(msg) Debug::out(__FILE__, __LINE__, "DEBUG", 5, (msg));
#define MARK() Debug::out(__FILE__, __LINE__, "MARK", 6, (msg));

class Debug {
public:
	static void setLogLevel(int);
	static void setFileLogLevel(int);
	static void setQuitLevel(int);

	// Should only really be called from the macro.
	static void out(const char*, int, std::string, int, std::string);

	// Starts putting logs in to a txt for the duration of the exectuion, or until endLog() is called
	static void startLog();
	static void startLog(std::string);
	static void startLog(std::string, std::string);
	static void endLog();

private:
	static int _logLevel;
	static int _fileLogLevel;
	static int _quitLevel;
	static std::ofstream _logFile;

	static bool _validate(int,int);
	static void _writeToLog(std::string);
	static void _createLog(std::string, std::string);
	static std::string _getDateTime(bool);
};

#endif //DEBUG_H
