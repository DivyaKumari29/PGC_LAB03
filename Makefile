CC     = gcc
OMP    = -fopenmp
BIN    = bin
OMPSRC = race critical atomic barrier compare_sync

all: $(OMPSRC) semaphore

$(BIN):
	mkdir -p $(BIN)

$(OMPSRC): %: src/%.c | $(BIN)
	$(CC) $< $(OMP) -o $(BIN)/$@

semaphore: src/semaphore.c | $(BIN)
	$(CC) $< -pthread -o $(BIN)/semaphore

run: all
	@echo "== race (4 threads) ==";      OMP_NUM_THREADS=4 ./$(BIN)/race
	@echo "== critical (4 threads) ==";  OMP_NUM_THREADS=4 ./$(BIN)/critical
	@echo "== atomic (4 threads) ==";    OMP_NUM_THREADS=4 ./$(BIN)/atomic
	@echo "== barrier (4 threads) ==";   OMP_NUM_THREADS=4 ./$(BIN)/barrier
	@echo "== semaphore ==";             ./$(BIN)/semaphore
	@echo "== compare_sync ==";          ./$(BIN)/compare_sync

clean:
	rm -rf $(BIN)

.PHONY: all run clean
