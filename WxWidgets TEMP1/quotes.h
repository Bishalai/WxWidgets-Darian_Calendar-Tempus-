#pragma once
#include<string>

using namespace std;
class quotes
{

private:


	std::string quotations[39] =
	{	"Keep Pushing - Bishal"

	
	}
		;

	int index;

public:

	quotes();

	string get_quote(int n);

	~quotes();

};

