all: estimator sorter toggle

estimator: estimator.c nop0.S nop100.S
	gcc estimator.c nop0.S nop100.S -std=c89 -g -o estimator

sorter: driver.c sorter.c
	gcc driver.c sorter.c -o driver

toggle: toggle.c toggle.S
	gcc toggle.c toggle.S -std=c89 -g -o toggle

.PHONY: clean
clean:
	rm -fv estimator
	rm -fv driver
	rm -fv toggle
	rm -fv *.o *~ \#*\# *.swp

include test.make