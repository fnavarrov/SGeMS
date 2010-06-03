#include "python_group_script.h"
#include <stdio.h>
#include <GsTLAppli/utils/gstl_messages.h>

#ifdef _DEBUG
#undef _DEBUG
#include <Python.h>
#define _DEBUG
#else
#include <Python.h>
#endif

Named_interface* Python_group_script::create_new_interface(std::string& _filename)
{
	return new Python_group_script(_filename);
}

Python_group_script::Python_group_script(const std::string& _filename) :
	filename_(_filename)
{
}

Python_group_script::~Python_group_script()
{
}

std::string Python_group_script::filename() const
{
	return filename_;
}

void Python_group_script::execute(const std::string grid_name, const std::string group_name) const
{
	PyRun_SimpleString(""
		"import redirect\n"
		"class CoutLogger:\n"
		"    def __init__(self):\n"
		"        self.buf = []\n"
		"    def write(self, data):\n"
		"        self.buf.append(data)\n"
		"        if data.endswith('\\n'):\n"
		"            redirect.sgems_cout(''.join(self.buf))\n"
		"            self.buf = []\n"
		"\n"
		"class CerrLogger:\n"
		"    def __init__(self):\n"
		"        self.buf = []\n"
		"    def write(self, data):\n"
		"        self.buf.append(data)\n"
		"        if data.endswith('\\n'):\n"
		"            redirect.sgems_cerr(''.join(self.buf))\n"
		"            self.buf = []\n"
		"\n"
		"import sys\n"
		"sys.stdout = CoutLogger()\n"
		"sys.stderr = CerrLogger()\n"
		"");

	FILE* fp = fopen(filename_.c_str(), "r");
	if (!fp)
	{
		GsTLcerr << "can't open file " << filename_ << gstlIO::end;
		return;
	}

	PyObject* module = PyImport_AddModule("__main__");
	PyObject* dictionary = PyModule_GetDict(module);
	PyObject* dictionary_copy = PyDict_Copy(dictionary);

	PyRun_File(fp, filename_.c_str(), Py_file_input, dictionary_copy, dictionary_copy);

	PyObject* function = PyDict_GetItemString(dictionary_copy, "sgems_execute_group_action");
	if (PyCallable_Check(function))
	{
		PyObject* result = PyObject_CallFunction(function, "ss", grid_name.c_str(), group_name.c_str());

		//		if (NULL == result)
		//		{
		//			std::cout << "execution failed\n";
		//		}

		Py_XDECREF(result);
	}

	Py_XDECREF(dictionary_copy);
	fclose(fp);
}
