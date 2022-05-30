#include "ProjectsManager.h"

namespace project_manager {

	ProjectsManager::ProjectsManager()
{
}

// Multithreading/ProcessCommunicator

inline void ProjectsManager::process_communicator()
{
	bool _exit = false;
	pr_cmm::ProcessCommunicator prc;
	std::thread th1(pr_cmm::sprocess_1, std::ref(_exit));
	std::thread th2(pr_cmm::sprocess_2, std::ref(_exit));
	th1.detach();
	th2.detach();

	std::cin.get();
	_exit = true;

}

void ProjectsManager::process_communicator_tests(int& argc, char* argv[])
{
	{
		testing::InitGoogleTest(&argc, argv);
		testing::GTEST_FLAG(filter) = "ProcessCommunicator_Tests*";
		RUN_ALL_TESTS();
	}
}

} // namespace project_manager