//
// Created by vilia on 2023/05/26.
//

#ifndef QUARKONCOMPILER_CODEGENERATION_H
#define QUARKONCOMPILER_CODEGENERATION_H
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
class CodeGenerator {
    std::shared_ptr<llvm::Module> _module;
    std::shared_ptr<llvm::LLVMContext> _context;
    std::shared_ptr<llvm::IRBuilder<>> _irBuilder;
public:
    
};
#endif //QUARKONCOMPILER_CODEGENERATION_H
