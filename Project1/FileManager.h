#pragma once
class FileManager
{
public:
	FileManager(void);
	~FileManager(void);
	void ModelLoad(const char * fileName);
	void ScriptLoad(const char * fileName);
};

