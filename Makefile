default:
	gcc main.c -o ash -larchive -lreadline

clean:
	rm -f ash
