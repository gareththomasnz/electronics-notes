#include <string>

namespace ISA {

enum OperandType {
    EMPTY,
    IMMEDIATE,
    REGISTER,
    REFERENCE_REGISTER,
    REFERENCE_REGISTER_OFFSET,
    REFERENCE_IMMEDIATE,
};
struct Operand {
    OperandType type;
    uint8_t reg;
    uint32_t immediate;
    uint16_t offset;
};

class InstructionImpl {
    friend class Instruction;
protected:
    uint32_t mEncoded = 0;
    std::string mOpcode;
    std::string mStrLOperand;
    std::string mStrROperand;
    std::string mStrXOperand;

    Operand mLOperand;
    Operand mROperand;
    Operand mXOperand;

    virtual void parseOpcode() {} ;
    void parseLeftOperand();
    void parseRightOperand();
    void parseExtraOperand();
    void parse();
    virtual void validate() {} ;
    virtual void encode() = 0;
public:
    InstructionImpl(const std::string opcode, const std::string leftOperand, const std::string rightOperand, const std::string extraOperand = "") :
        mOpcode(opcode), mStrLOperand(leftOperand), mStrROperand(rightOperand), mStrXOperand(extraOperand) {
    } ;
    uint32_t getEncoding() { return mEncoded;}; /* TODO: call parse() only on getEncoding() */
};

class HaltInstructionImpl : public InstructionImpl {
    using InstructionImpl::InstructionImpl;
    void encode();
};

class NopInstructionImpl : public InstructionImpl {
    using InstructionImpl::InstructionImpl;
    void encode();
};

class LoadInstructionImpl : public InstructionImpl {
    using InstructionImpl::InstructionImpl;
    void parseFlags();
    void parseOpcode();
    void validate();
    void encode();
};

class StoreInstructionImpl : public InstructionImpl {
    using InstructionImpl::InstructionImpl;
    void parseFlags();
    void parseOpcode();
    void validate();
    void encode();
};

class JumpInstructionImpl : public InstructionImpl {
    bool mIsLink = false;
    bool mIsRelative = false;
    using InstructionImpl::InstructionImpl;
    size_t parseFlags();
    void parseOpcode();
    void validate();
    void encode();
};

class AddInstructionImpl : public InstructionImpl {
    bool mIsUpper = false;
    using InstructionImpl::InstructionImpl;
    void parseOpcode();
    void validate();
    void encode();
};

class MulInstructionImpl : public InstructionImpl {
    using InstructionImpl::InstructionImpl;
    void validate();
    void encode();
};

class PushInstructionImpl : public InstructionImpl {
    using InstructionImpl::InstructionImpl;
    void validate();
    void encode();
};

class PopInstructionImpl : public InstructionImpl {
    using InstructionImpl::InstructionImpl;
    void validate();
    void encode();
};


class Instruction {
public:
    typedef enum {
        LOAD,
        JUMP,
        STORE,
        ADD,
        MUL,
        XOR,
        HALT,
        PUSH,
        POP,
        NOP,
    } InstructionType;


    Instruction(const std::string mnemonic);
    ~Instruction();
    uint32_t getEncoding() { return mInstruction->getEncoding();};
    static Operand parseOperand(const std::string operand);

    private:
        InstructionType mType;
        InstructionImpl* mInstruction = nullptr;
        const std::string mMnemonic;

        void parse();
};

} // end namespace ISA
