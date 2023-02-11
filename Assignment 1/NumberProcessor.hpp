#ifndef NUMBER_PROCESSOR_HPP
#define NUMBER_PROCESSOR_HPP

class NumberProcessor
{
    public:
        NumberProcessor();
        ~NumberProcessor();
        void import_file();
        void append_number();
        void remove_number();
        void find_num() const;
        void replace_num();
        void print_nums() const;
        void start_tui();
    
    private:
        int* numbers;
        int numbers_capacity;
        int used_numbers_size;

        void append_number(int num);
        void extend_array();
        void wait_for_enter_key() const;
        int prompt_for_number(std::string prompt) const;
        int prompt_for_number(std::string prompt, int beginRange, int endRange) const;
};

#endif
