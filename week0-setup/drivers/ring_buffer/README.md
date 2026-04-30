# Ring Buffer Driver — TDD Exercise

## Purpose
Week 0 TDD practice. Goal is not the ring buffer itself but learning
the Red → Green → Refactor cycle using Ceedling + Unity.

## Data Structure
```c
#define BUFFER_SIZE 10

typedef struct {
    uint8_t arr[BUFFER_SIZE];
    int head;
    int tail;
} RingBuffer;
```

## API
| Function | Description |
|---|---|
| `rb_init(rb)` | Zero out head and tail |
| `rb_push(rb, data)` | Write at head, advance head. Drops data if full |
| `rb_pop(rb)` | Read from tail, advance tail. Returns -1 if empty |
| `rb_is_full(rb)` | True when (head+1) % SIZE == tail |
| `rb_is_empty(rb)` | True when head == tail |

## Key Concepts
- Head advances on push, tail advances on pop
- Wrap-around via modulo: (index + 1) % BUFFER_SIZE
- Full condition sacrifices one slot to distinguish full vs empty
- No dynamic memory — fixed size, safe for embedded use

## Running Tests
```bash
ceedling test:all
```

## Test Results
TESTED: 5 | PASSED: 5 | FAILED: 0
