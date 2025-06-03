#include <header/ast.h>

AST *ast_new(AST ast){
    AST *ptr = mallow(sizeof(AST));
    if(!ptr){
        printf("Memory Allocation failed");
    }
    *ptr = ast;
    return ptr;
}

 AST *term_ = ast_new((AST){
    AST_ADD, 
    {
      .AST_ADD=(struct AST_ADD){
        ast_new((AST){
          AST_NUMBER, 
          {.AST_NUMBER=(struct AST_NUMBER){5}}
        }),
        ast_new((AST){
          AST_NUMBER, 
          {.AST_NUMBER=(struct AST_NUMBER){1}}}
        ),
      }
    }
  });