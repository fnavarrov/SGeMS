#ifndef PYTHON_GROUP_SCRIPT_H_
#define PYTHON_GROUP_SCRIPT_H_

#include <GsTLAppli/utils/named_interface.h>
#include <GsTLAppli/actions/common.h>

#include <vector>

class ACTIONS_DECL Python_group_script: public Named_interface
{
public:
	static Named_interface* create_new_interface(std::string&);

	Python_group_script(const std::string& filename);
	virtual ~Python_group_script();

	std::string filename() const;

	void execute(const std::string grid_name, const std::string group_name) const;

protected:
	std::string filename_;
};

#endif /* PYTHON_GROUP_SCRIPT_H_ */
