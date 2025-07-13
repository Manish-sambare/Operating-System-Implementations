def lru_page_replacement(pages, capacity):
    memory = []
    page_faults = 0
    recent_usage = {}

    print(f"\nPage Reference String: {pages}")
    print(f"Memory Capacity: {capacity}\n")

    for time, page in enumerate(pages):
        if page not in memory:
            if len(memory) < capacity:
                memory.append(page)
            else:
                # Find least recently used page
                lru_page = min(recent_usage, key=recent_usage.get)
                memory[memory.index(lru_page)] = page
                print(f"Removed LRU page {lru_page} to insert {page}")
            page_faults += 1
            print(f"Page {page} caused a fault. Memory: {memory}")
        else:
            print(f"Page {page} is already in memory. Memory: {memory}")

        recent_usage[page] = time  # Update recent usage

    print(f"\nTotal Page Faults: {page_faults}")
    print(f"Final Memory State: {memory}")


# Example usage
if __name__ == "__main__":
    pages = [7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3]
    capacity = 3
    lru_page_replacement(pages, capacity)
