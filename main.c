#include "ft_printf.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

void	print_tag(t_tag *tag)
{
	char *prefixes[] = {"", "-", "+", " ", "0x", "0X"};

	printf("t_tag {\n");
	printf("  properties:\n");
	printf("    left_justify:  %d\n", tag->properties.left_justify);
	printf("    plus:          %d\n", tag->properties.plus);
	printf("    space:         %d\n", tag->properties.space);
	printf("    prefix:        %d\n", tag->properties.prefix);
	printf("    zeroes:        %d\n", tag->properties.zeroes);
	printf("    padding:       %d\n", tag->properties.padding);
	printf("    precision:     %d\n", tag->properties.precision);
	printf("    specifier:     %c\n", tag->properties.specifier);
	printf("  range:\n");
	printf("    start:         %lu\n", tag->range.start);
	printf("    length:        %zu\n", tag->range.length);
	printf("  result:\n");
	printf("    str:           '%s'\n", tag->result.str);
	printf("    prefix:        '%s'\n", prefixes[tag->result.prefix]);
	// printf("    size_virtual:  %zu\n", tag->result.size_virtual);
	// printf("    size_actual:   %zu\n", tag->result.size_actual);
	printf("    size:          %zu\n", tag->result.size);
	printf("}\n");
}

int	main(void)
{
	t_buffer buffer;
	t_tag tag;

	(void) tag;
	(void) buffer;

	// const char *format = "%+.2d\n";
	// if (init_buffer(format, &buffer))
	// 	return (1);
	// init_tag(&tag);
	// if (parse_tag(&buffer, &tag))
	// 	return (2);
	// tag.result.str = strdup("100");
	// tag.result.prefix = PREFIX_0X_LOWER;
	// tag.result.size_virtual = 3;
	// tag.result.size_actual = 3;
	// prepare_str(&tag);
	// print_tag(&tag);
	// if (apply_precision(&tag))
	// 	return (3);
	// if (apply_prefix(&tag))
	// 	return (4);
	// printf("%s\n", tag.result.str);

	// ft_printf(format, 5);

	// int n;

	// (void) n;

	// printf("====================\n");
	// n = printf("%020s\n", "abcdefghi");
	// printf("%d\n", n);
	// n = printf("%020.3s\n", "abcdefghi");
	// printf("%d\n", n);
	// n = printf("%+.3d\n", 5);
	// printf("%d\n", n);
	// n = printf("%0+20.3d\n", 5);
	// printf("%d\n", n);
	// n = printf("%+.3i\n", 5);
	// printf("%d\n", n);
	// n = printf("%0+20.3i\n", 5);
	// printf("%d\n", n);
	// n = printf("%+.3u\n", 5);
	// printf("%d\n", n);
	// n = printf("%0+20.3u\n", 5);
	// printf("%d\n", n);
	// n = printf("%+.3x\n", 15);
	// printf("%d\n", n);
	// n = printf("%0+20.3x\n", 15);
	// printf("%d\n", n);
	// n = printf("%+.3p\n", 15);
	// printf("%d\n", n);
	// n = printf("%0+20.3p\n", 15);
	// printf("%d\n", n);
	// n = printf("%+.5c\n", 49);
	// printf("%d\n", n);
	// n = printf("%0+20.5c\n", 49);
	// printf("%d\n", n);
	// printf("====================\n");
	// n = ft_printf("%020s\n", "abcdefghi");
	// printf("%d\n", n);
	// n = ft_printf("%020.3s\n", "abcdefghi");
	// printf("%d\n", n);
	// n = ft_printf("%+.3d\n", 5);
	// printf("%d\n", n);
	// n = ft_printf("%0+20.3d\n", 5);
	// printf("%d\n", n);
	// n = ft_printf("%+.3i\n", 5);
	// printf("%d\n", n);
	// n = ft_printf("%0+20.3i\n", 5);
	// printf("%d\n", n);
	// n = ft_printf("%+.3u\n", 5);
	// printf("%d\n", n);
	// n = ft_printf("%0+20.3u\n", 5);
	// printf("%d\n", n);
	// n = ft_printf("%+.3x\n", 15);
	// printf("%d\n", n);
	// n = ft_printf("%0+20.3x\n", 15);
	// printf("%d\n", n);
	// n = ft_printf("%+.3p\n", 15);
	// printf("%d\n", n);
	// n = ft_printf("%0+20.3p\n", 15);
	// printf("%d\n", n);
	// n = ft_printf("%+.5c\n", 49);
	// printf("%d\n", n);
	// n = ft_printf("%0+20.5c\n", 49);
	// printf("%d\n", n);

	// printf(" %d\n", printf("'%c'", 0));
	// printf(" %d\n", ft_printf("'%c'", 0));

	// ft_printf("-%010d-%.5d-%+d-\n", 1, 2, 3);
	// printf("-%010d-%.5d-%+d-\n", 1, 2, 3);

	int ntest = 0;
	{
		const char *format = "'%0 10d'\n";
		int arg1 = 5;

		printf("\n== TEST %03d =============\n", ntest++);
		printf("o: ");
		int a = printf(format, arg1);
		printf("l: %d\n", a);
		ft_printf("c: ");
		int b = ft_printf(format, arg1);
		printf("l: %d\n", b);
	}
	{
		const char *format = "'%0+10d'\n";
		int arg1 = 5;

		printf("\n== TEST %03d =============\n", ntest++);
		printf("o: ");
		int a = printf(format, arg1);
		printf("l: %d\n", a);
		ft_printf("c: ");
		int b = ft_printf(format, arg1);
		printf("l: %d\n", b);
	}
	{
		const char *format = "'% 10d'\n";
		int arg1 = 5;

		printf("\n== TEST %03d =============\n", ntest++);
		printf("o: ");
		int a = printf(format, arg1);
		printf("l: %d\n", a);
		ft_printf("c: ");
		int b = ft_printf(format, arg1);
		printf("l: %d\n", b);
	}
	{
		const char *format = "'% +10d'\n";
		int arg1 = 5;

		printf("\n== TEST %03d =============\n", ntest++);
		printf("o: ");
		int a = printf(format, arg1);
		printf("l: %d\n", a);
		ft_printf("c: ");
		int b = ft_printf(format, arg1);
		printf("l: %d\n", b);
	}
	{
		const char *format = "'%-+10d'\n";
		int arg1 = 5;

		printf("\n== TEST %03d =============\n", ntest++);
		printf("o: ");
		int a = printf(format, arg1);
		printf("l: %d\n", a);
		ft_printf("c: ");
		int b = ft_printf(format, arg1);
		printf("l: %d\n", b);
	}
	{
		const char *format = "'% -10d'\n";
		int arg1 = 5;

		printf("\n== TEST %03d =============\n", ntest++);
		printf("o: ");
		int a = printf(format, arg1);
		printf("l: %d\n", a);
		ft_printf("c: ");
		int b = ft_printf(format, arg1);
		printf("l: %d\n", b);
	}
	{
		const char *format = "'%+-010d'\n";
		int arg1 = 5;

		printf("\n== TEST %03d =============\n", ntest++);
		printf("o: ");
		int a = printf(format, arg1);
		printf("l: %d\n", a);
		ft_printf("c: ");
		int b = ft_printf(format, arg1);
		printf("l: %d\n", b);
	}
	{
		const char *format = "'%+10.5d'\n";
		int arg1 = 5;

		printf("\n== TEST %03d =============\n", ntest++);
		printf("o: ");
		int a = printf(format, arg1);
		printf("l: %d\n", a);
		ft_printf("c: ");
		int b = ft_printf(format, arg1);
		printf("l: %d\n", b);
	}
	{
		const char *format = "'%0+10.5d'\n";
		int arg1 = 5;

		printf("\n== TEST %03d =============\n", ntest++);
		printf("o: ");
		int a = printf(format, arg1);
		printf("l: %d\n", a);
		ft_printf("c: ");
		int b = ft_printf(format, arg1);
		printf("l: %d\n", b);
	}
	{
		const char *format = "'%0+-10.5d'\n";
		int arg1 = 5;

		printf("\n== TEST %03d =============\n", ntest++);
		printf("o: ");
		int a = printf(format, arg1);
		printf("l: %d\n", a);
		ft_printf("c: ");
		int b = ft_printf(format, arg1);
		printf("l: %d\n", b);
	}
	{
		const char *format = "'%c%c%c'\n";
		int arg1 = 0;
		int arg2 = 0;
		int arg3 = 0;

		printf("\n== TEST %03d =============\n", ntest++);
		printf("o: ");
		int a = printf(format, arg1, arg2, arg3);
		printf("l: %d\n", a);
		ft_printf("c: ");
		int b = ft_printf(format, arg1, arg2, arg3);
		printf("l: %d\n", b);
	}
	{
		const char *format = "'%c%c%c'\n";
		int arg1 = 27;
		int arg2 = 27;
		int arg3 = 27;

		printf("\n== TEST %03d =============\n", ntest++);
		printf("o: ");
		int a = printf(format, arg1, arg2, arg3);
		printf("l: %d\n", a);
		ft_printf("c: ");
		int b = ft_printf(format, arg1, arg2, arg3);
		printf("l: %d\n", b);
	}
	{
		const char *format = "' %c %c %c '";
		int arg1 = '0';
		int arg2 = 0;
		int arg3 = '1';

		printf("\n== TEST %03d =============\n", ntest++);
		printf("o: ");
		int a = printf(format, arg1, arg2, arg3);
		printf("\nl: %d\n", a);
		ft_printf("c: ");
		int b = ft_printf(format, arg1, arg2, arg3);
		printf("\nl: %d\n", b);
	}
	{
		const char *format = "' %c %c %c '";
		int arg1 = '2';
		int arg2 = '1';
		int arg3 = 0;

		printf("\n== TEST %03d =============\n", ntest++);
		printf("o: ");
		int a = printf(format, arg1, arg2, arg3);
		printf("\nl: %d\n", a);
		ft_printf("c: ");
		int b = ft_printf(format, arg1, arg2, arg3);
		printf("\nl: %d\n", b);
	}
	{
		const char *format = "' %c %c %c '";
		int arg1 = 0;
		int arg2 = '1';
		int arg3 = '2';

		printf("\n== TEST %03d =============\n", ntest++);
		printf("o: ");
		int a = printf(format, arg1, arg2, arg3);
		printf("\nl: %d\n", a);
		ft_printf("c: ");
		int b = ft_printf(format, arg1, arg2, arg3);
		printf("\nl: %d\n", b);
	}
	{
		const char *format = " NULL %s NULL ";
		char *arg1 = NULL;

		printf("\n== TEST %03d =============\n", ntest++);
		printf("o: ");
		int a = printf(format, arg1);
		printf("\nl: %d\n", a);
		ft_printf("c: ");
		int b = ft_printf(format, arg1);
		printf("\nl: %d\n", b);
	}
	{
		const char *format = " %x ";
		long arg1 = LONG_MAX;

		printf("\n== TEST %03d =============\n", ntest++);
		printf("o: ");
		int a = printf(format, arg1);
		printf("\nl: %d\n", a);
		ft_printf("c: ");
		int b = ft_printf(format, arg1);
		printf("\nl: %d\n", b);
	}
	{
		// const char *format = " %% ";

		printf("\n== TEST %03d =============\n", ntest++);
		printf("o: ");
		int a = printf(" %% ");
		printf("\nl: %d\n", a);
		ft_printf("c: ");
		int b = ft_printf(" %% ");
		printf("\nl: %d\n", b);
	}
	{
		const char *format = "%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%";

		printf("\n== TEST %03d =============\n", ntest++);
		printf("o: ");
		int a = printf(format, 'A', "42", 42, 42, 42, 42, 42, 'B', "-42", -42, -42, -42, -42, 42, 'C', "0", 0, 0, 0, 0, 42, 0);
		printf("\nl: %d\n", a);
		ft_printf("c: ");
		int b = ft_printf(format, 'A', "42", 42, 42, 42, 42, 42, 'B', "-42", -42, -42, -42, -42, 42, 'C', "0", 0, 0, 0, 0, 42, 0);
		printf("\nl: %d\n", b);
	}
	{
		const char *format = " %#x ";
		int arg1 = 0;

		printf("\n== TEST %03d =============\n", ntest++);
		printf("o: ");
		int a = printf(format, arg1);
		printf("\nl: %d\n", a);
		ft_printf("c: ");
		int b = ft_printf(format, arg1);
		printf("\nl: %d\n", b);
	}
	{
		const char *format = " %#x ";
		int arg1 = 1;

		printf("\n== TEST %03d =============\n", ntest++);
		printf("o: ");
		int a = printf(format, arg1);
		printf("\nl: %d\n", a);
		ft_printf("c: ");
		int b = ft_printf(format, arg1);
		printf("\nl: %d\n", b);
	}
	{
		const char *format = " %p ";
		int arg1 = 0;

		printf("\n== TEST %03d =============\n", ntest++);
		printf("o: ");
		int a = printf(format, arg1);
		printf("\nl: %d\n", a);
		ft_printf("c: ");
		int b = ft_printf(format, arg1);
		printf("\nl: %d\n", b);
	}
	{
		const char *format = "%.d";
		int arg1 = 0;

		printf("\n== TEST %03d =============\n", ntest++);
		printf("o: ");
		int a = printf(format, arg1);
		printf("\nl: %d\n", a);
		ft_printf("c: ");
		int b = ft_printf(format, arg1);
		printf("\nl: %d\n", b);
	}
	{
		const char *format = "%.u";
		int arg1 = 0;

		printf("\n== TEST %03d =============\n", ntest++);
		printf("o: ");
		int a = printf(format, arg1);
		printf("\nl: %d\n", a);
		ft_printf("c: ");
		int b = ft_printf(format, arg1);
		printf("\nl: %d\n", b);
	}
	{
		const char *format = "%#.x";
		int arg1 = 0;

		printf("\n== TEST %03d =============\n", ntest++);
		printf("o: ");
		int a = printf(format, arg1);
		printf("\nl: %d\n", a);
		ft_printf("c: ");
		int b = ft_printf(format, arg1);
		printf("\nl: %d\n", b);
	}
	{
		const char *format = "%#.p";
		int arg1 = 0;

		printf("\n== TEST %03d =============\n", ntest++);
		printf("o: ");
		int a = printf(format, arg1);
		printf("\nl: %d\n", a);
		ft_printf("c: ");
		int b = ft_printf(format, arg1);
		printf("\nl: %d\n", b);
	}
	{
		const char *format = "%05c d";
		// int arg1 = 49;
		int arg1 = 0;

		printf("\n== TEST %03d =============\n", ntest++);
		printf("o: ");
		int a = printf(format, arg1);
		printf("\nl: %d\n", a);
		ft_printf("c: ");
		int b = ft_printf(format, arg1);
		printf("\nl: %d\n", b);
	}
	{
		const char *format = "' %c %c %c '";
		int arg1 = 0;
		int arg2 = '1';
		int arg3 = '2';

		printf("\n== TEST %03d =============\n", ntest++);
		printf("o: ");
		int a = printf(format, arg1, arg2, arg3);
		printf("\nl: %d\n", a);
		ft_printf("c: ");
		int b = ft_printf(format, arg1, arg2, arg3);
		printf("\nl: %d\n", b);
	}
	{
		// const char *format = "%-58.131%";

		printf("\n== TEST %03d =============\n", ntest++);
		printf("o: ");
		int a = printf("%-58.131%");
		printf("\nl: %d\n", a);
		ft_printf("c: ");
		int b = ft_printf("%-58.131%");
		printf("\nl: %d\n", b);
	}

	ft_printf("%.10%\n");


	// {
	// 	const char *format = "d";
	// 	int arg1 = 49;

	// 	printf("\n== TEST %03d =============\n", ntest++);
	// 	printf("o: ");
	// 	int a = printf(format, arg1);
	// 	printf("\nl: %d\n", a);
	// 	ft_printf("c: ");
	// 	int b = ft_printf(format, arg1);
	// 	printf("\nl: %d\n", b);
	// }

	// write(1, " 1 \0 2 ", 7);

	// printf("%0 10d\n", 5);
	// ft_printf("%0 10d\n", 5);
	// printf("%0+10d\n", 5);
	// ft_printf("%0+10d\n", 5);

	// printf("% 10d\n", 5);
	// ft_printf("% 10d\n", 5);
	// printf("%+10d\n", 5);
	// ft_printf("%+10d\n", 5);
	// printf("%0 10d\n", 5);
	// ft_printf("%0 10d\n", 5);
	// printf("%05c\n", 0);
	// ft_printf("%05c\n", 0);

	// printf("%.3c\n", 'c');
	// printf("%.3s\n", "abcdef");
	// printf("%.30p\n", 15489856);
	// printf("%.3d\n", 1);
	// printf("%.3i\n", 1);
	// printf("%.3u\n", 1);
	// printf("%.3x\n", 1);
	// printf("%.3X\n", 1);
	// printf("%.3%\n");

	// printf("%010c\n", 'c');
	// printf("%010s\n", "abcdef");
	// printf("%010p\n", 15489856);
	// printf("%010d\n", 1);
	// printf("%010i\n", 1);
	// printf("%010u\n", 1);
	// printf("%010x\n", 1);
	// printf("%010X\n", 1);
	// printf("%010%\n");

	// printf("%10c\n", 'c');
	// printf("%10s\n", "abcdef");
	// printf("%10p\n", 15489856);
	// printf("%10d\n", 1);
	// printf("%10i\n", 1);
	// printf("%10u\n", 1);
	// printf("%10x\n", 1);
	// printf("%10X\n", 1);
	// printf("%10%\n");

	// printf("%.10s\n", "abcdef");

	// printf("%.5%");

	// printf("% u\n", 5);

	// for(int i = 0; i < 32; i++)
	// {
	// 	// char *str = calloc(2, 1);
	// 	// *str = (char) i;
	// 	int n = printf("%3d ('%c' ", i, (char) i);
	// 	printf("%d)\n", n);
	// 	// free(str);
	// }

	// printf("%d\n", strlen("\x27"));
	// printf("'%05c'\n", 31);

	// char *str = malloc(20);
	// itoa_base2(1589, "0123456789", &str);
	// printf("%s\n", str);
	// itoa_base2(-1589, "0123456789", &str);
	// printf("%s\n", str);
	// itoa_base2(0, "0123456789", &str);
	// printf("%s\n", str);
	// itoa_base2(-0, "0123456789", &str);
	// printf("%s\n", str);
	// itoa_base2(1589, "0123456789abcdef", &str);
	// printf("%s\n", str);
	// itoa_base2(-1589, "0123456789abcdef", &str);
	// printf("%s\n", str);
	// itoa_base2(1589, "0123456789abcdef", &str);
	// printf("%s\n", str);
	// itoa_base2(1589, "0123456789abcdef", &str);
	// printf("%s\n", str);
	// itoa_base2(1589, "0123456789abcdef", &str);
	// printf("%s\n", str);

	// if (advance_cursor(&buffer))
	// 	return (2);
	// printf("%d\n", buffer.size_actual);

	// char *s1 = strdup("test");
	// padstr2(20, 0, 0, &s1);
	// printf("'%s'\n", s1);
	// char *s2 = strdup("test");
	// padstr2(20, 1, 0, &s2);
	// printf("'%s'\n", s2);
	// char *s3 = strdup("test");
	// padstr2(20, 0, 1, &s3);
	// printf("'%s'\n", s3);
	// char *s4 = strdup("test");
	// padstr2(20, 1, 1, &s4);
	// printf("'%s'\n", s4);
	// char *s5 = strdup("test");
	// padstr2(2, 0, 0, &s5);
	// printf("'%s'\n", s5);


	// // printf("%10.5d\n", -10);
	// // printf(" | %d\n", printf("'%03c'", 0));
	// // printf(" | %d\n", printf("'%s'", ""));

	// printf("%.3c\n", 'a');
	// printf("%.3s\n", "abcdef");
	// printf("%.3p\n", "s");
	// printf("%.3d\n", 1);
	// printf("%.3i\n", 1);
	// printf("%.3u\n", 1);
	// printf("%.3x\n", 15);
	// printf("%10.30X\n", 15);
	// printf("%.3%\n");


	return (0);
}