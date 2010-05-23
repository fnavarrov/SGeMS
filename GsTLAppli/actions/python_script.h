#ifndef PYTHON_SCRIPT_H_
#define PYTHON_SCRIPT_H_

#include <GsTLAppli/utils/named_interface.h>
#include <GsTLAppli/actions/common.h>

#include <vector>

class ACTIONS_DECL Python_script: public Named_interface
{
public:
	static Named_interface* create_new_interface(std::string&);

	Python_script(const std::string& filename);
	virtual ~Python_script();

	std::string filename() const;

	void execute(const std::string grid_name, const std::vector<std::string> prop_names) const;

protected:
	std::string filename_;
};

#endif /* PYTHON_SCRIPT_H_ */
