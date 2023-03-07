CC = gcc CFLAGS = -std =
    c11 - Wall - Werror -
    Wextra

            all
    :../../
        build /
        Quest_3

            ../
            ../ build /
        Quest_3 : data_process.o decision.o main_executable_module.o data_io.o data_sort.o data_stat
            .o $(CC) $(CFLAGS)
                      data_process.o decision.o main_executable_module.o data_io.o data_sort.o data_stat.o -
    o../../ build /
        Quest_3

            data_process.o :../
        data_module / data_process.c../ data_module / data_process.h $(CC) $(CFLAGS) -
    c../ data_module /
        data_process
            .c

                decision.o :../
        yet_another_decision_module / decision.c../ yet_another_decision_module / decision.h $(CC) $(CFLAGS) -
    c../ yet_another_decision_module /
        decision
            .c

                main_executable_module.o : main_executable_module
            .c $(CC) $(CFLAGS) -
    c../ main_executable_module /
        main_executable_module
            .c

                data_io.o :../
        data_libs / data_io.c../ data_libs / data_io.h $(CC) $(CFLAGS) -
    c../ data_libs /
        data_io
            .c

                data_sort.o :../
        data_libs / data_sort.c../ data_libs / data_sort.h $(CC) $(CFLAGS) -
    c../ data_libs /
        data_sort
            .c

                data_stat.o :../
        data_libs / data_stat.c../ data_libs / data_stat.h $(CC) $(CFLAGS) -
    c../ data_libs /
        data_stat
            .c

                libdata_stat.a : $(CC) -
    c../ data_libs /
        data_stat.c ar rc data_stat.a data_stat.o ranlib data_stat
            .a

                build_with_static : data_process.o decision.o main_executable_module.o data_io.o data_sort
            .o libdata_stat.a $(CC) $(CFLAGS) data_process.o decision.o main_executable_module.o data_io
            .o data_sort.o -
    L.data_stat.a -
    o../../ build /
        Quest_5

            data_process.so : data_process.o
                              $(CC) -
    shared - c - fPIC../ data_module / data_process.c -
    o libdata_process
        .so

            build_with_dynamic : data_process.so decision.o main_executable_module.o data_io.o data_sort
        .o data_stat.o $(CC) $(CFLAGS) decision.o main_executable_module.o data_io.o data_stat.o data_sort.o -
    L.libdata_process.so -
    o../../ build /
        Quest_6

            clean : rm -
    rf *.o *.a *.so../../ build/*.so rebild