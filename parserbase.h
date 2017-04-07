// Generated by Bisonc++ V4.13.01 on Thu, 06 Apr 2017 23:52:30 +0530

#ifndef ParserBase_h_included
#define ParserBase_h_included

#include <exception>
#include <vector>
#include <iostream>


namespace // anonymous
{
    struct PI__;
}



class ParserBase
{
    public:
// $insert tokens

    // Symbolic tokens:
    enum Tokens__
    {
        OR = 257,
        AND,
        EQUAL_TO,
        NOT_EQUAL_TO,
        LESS_THAN,
        LESS_THAN_EQUAL,
        GREATER_THAN,
        GREATER_THAN_EQUAL,
        UMINUS,
        NOT,
        INTEGER_NUMBER,
        DOUBLE_NUMBER,
        NAME,
        VOID,
        INTEGER,
        FLOAT,
        DO,
        WHILE,
        IF,
        ELSE,
        ASSIGN,
        RETURN,
    };

// $insert STYPE
union STYPE__
{
 int integer_value;
 double double_value;
 std::string * string_value;
 vector<std::string> *var_list;
 vector<Symbol_Table_Entry * > *decl_entry_list;
 vector<pair< Data_Type, string> > *declaration_list;
 Symbol_Table * symbol_table;
 Sequence_Ast *sequence_Ast;
 Ast * ast;
 Procedure *proc;
 list<pair<Data_Type, string> > *arg_list;
 pair<Data_Type, string> *arg;
 Return_Ast *ret_ast;
 Print_Ast *p_ast;
 Func_Call_Ast *f_ast;
};


    private:
        int d_stackIdx__;
        std::vector<size_t>   d_stateStack__;
        std::vector<STYPE__>  d_valueStack__;

    protected:
        enum Return__
        {
            PARSE_ACCEPT__ = 0,   // values used as parse()'s return values
            PARSE_ABORT__  = 1
        };
        enum ErrorRecovery__
        {
            DEFAULT_RECOVERY_MODE__,
            UNEXPECTED_TOKEN__,
        };
        bool        d_debug__;
        size_t      d_nErrors__;
        size_t      d_requiredTokens__;
        size_t      d_acceptedTokens__;
        int         d_token__;
        int         d_nextToken__;
        size_t      d_state__;
        STYPE__    *d_vsp__;
        STYPE__     d_val__;
        STYPE__     d_nextVal__;

        ParserBase();

        void ABORT() const;
        void ACCEPT() const;
        void ERROR() const;
        void clearin();
        bool debug() const;
        void pop__(size_t count = 1);
        void push__(size_t nextState);
        void popToken__();
        void pushToken__(int token);
        void reduce__(PI__ const &productionInfo);
        void errorVerbose__();
        size_t top__() const;

    public:
        void setDebug(bool mode);
}; 

inline bool ParserBase::debug() const
{
    return d_debug__;
}

inline void ParserBase::setDebug(bool mode)
{
    d_debug__ = mode;
}

inline void ParserBase::ABORT() const
{
    throw PARSE_ABORT__;
}

inline void ParserBase::ACCEPT() const
{
    throw PARSE_ACCEPT__;
}

inline void ParserBase::ERROR() const
{
    throw UNEXPECTED_TOKEN__;
}


// As a convenience, when including ParserBase.h its symbols are available as
// symbols in the class Parser, too.
#define Parser ParserBase


#endif


