#include <cstdio>
#include "tree.h"
#include "tokens.h"

extern MethodList *methods;
extern MainMethod *main_method;
extern DeclList * declarationList;

int main()
{
   	main_method = 0;
    yyparse();
    if(declarationList!=0)
    {
    	list<Declaration*>::iterator it=declarationList->begin();
    	
		while(it!=declarationList->end())
		{
			Declaration *de=*it;
			de->execute();
			it++;
		}
	}
    if (methods != 0) {
       	MethodList::iterator it=methods->begin();
    
		while(it!= methods->end())
		{
			Method* m=*it;
			m->execute();
			it++;
		}
    }
    
    main_method->execute();
}
