def fifo_page_replacement(pages, capacity):
    memory = []
    page_faults = 0
    index = 0  # FIFO pointer

    print(f"\nPage Reference String: {pages}")
    print(f"Memory Capacity: {capacity}\n")

    for page in pages:
        if page not in memory:
            if len(memory) < capacity:
                memory.append(page)
            else:
                print(f"Removing page {memory[index]} to insert {page}")
                memory[index] = page
                index = (index + 1) % capacity
            page_faults += 1
            print(f"Page {page} caused a fault. Memory: {memory}")
        else:
            print(f"Page {page} already in memory. Memory: {memory}")

    print(f"\nTotal Page Faults: {page_faults}")
    print(f"Final Memory State: {memory}")


# Example usage
if __name__ == "__main__":
    pages = [7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3]
    capacity = 3
    fifo_page_replacement(pages, capacity)
