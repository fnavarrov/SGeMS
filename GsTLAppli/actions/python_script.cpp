#include "python_script.h"
#include <stdio.h>
#include <GsTLAppli/utils/gstl_messages.h>

#ifdef _DEBUG
#undef _DEBUG
#include <Python.h>
#define _DEBUG
#else
#include <Python.h>
#endif

Named_interface* Python_script::create_new_interface(std::string& _filename)
{
	return new Python_script(_filename);
}

Python_script::Python_script(const std::string& _filename) :
	filename_(_filename)
{
}

Python_script::~Python_script()
{
}

std::string Python_script::filename() const
{
	return filename_;
}

void Python_script::execute(const std::string grid_name, const std::vector<std::string> prop_names) const
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

	PyObject* function = PyDict_GetItemString(dictionary_copy, "sgems_execute_action");
	if (PyCallable_Check(function))
	{
		//		PyObject* properties = PyTuple_New(prop_names.size());
		//		for (int i = 0; i < prop_names.size(); ++i)
		//		{
		//			PyTuple_SetItem(properties, i, PyString_FromString(prop_names.at(i).c_str()));
		//		}
		//		PyObject* result = PyObject_CallFunction(function, "so", grid_name.c_str(), properties);
		PyObject* result = PyObject_CallFunction(function, "s[s]", grid_name.c_str(), prop_names.at(0).c_str());

		if (NULL == result)
		{
			std::cout << "execution failed\n";
		}

		Py_XDECREF(result);
	}

	Py_XDECREF(dictionary_copy);
	fclose(fp);
}
