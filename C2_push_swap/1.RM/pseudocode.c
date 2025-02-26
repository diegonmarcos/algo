
QUICK SORT ALGO FOR TWO STACKS

// Recursive Split

// Initial Call
void	quick_sort_pushswap(void *list_program)
{
	// Initialize the first chunk to sort, which is the entire stack A
	chunk_to_sort = 
	{
		min: 0, 
		max: size of stack A - 1,
		size: size of stack A,
		position: TOP_A
	}
	
	// Start the recursive sorting process
	recursive_split_chunk(chunk_to_sort, list_program);
}

// RECURSIVE SPLIT
void	recursive_split_chunk(void *chunk_to_sort,void	*list_program)
{
	 
	// Calculate pivots and initialize split_chunks structure.
		pivot_calculation(chunk_to_sort, split_chunks);
			split_chunks = (t_split_chunks)
			{
				min_number;
				pivot1;
				pivot2;
				max_number;
				position_from;
				max;
				mid;
				min;
			}

	// Check if the chunk is small enough to be sorted directly
		IF chunk_to_sort.size is less than or equal to 3 THEN
		{
			// Base case: Merge and sort small chunks
				merge_back_and_sort(chunk_to_sort, split_chunks, list_program);
		}

	// Split the current chunk into three sub-chunks
		split_chunk(chunk_to_sort, split_chunks, list_program);

	// Recursively SPLIT the three sub-chunks, created in the order max, mid, min
		recursive_split_chunk(split_chunks.max, list_program);
		recursive_split_chunk(split_chunks.mid, list_program);
		recursive_split_chunk(split_chunks.min, list_program);
}


// SPLIT CHUNK FUNCTION
void	split_chunk(void chunk_to_sort, void split_chunks, void list_program)
{
	// Check if list is already sorted
		is_sorted_linked_list_push(list_program);

	// Calculate pivot values (details omitted, just mentioning the purpose)
		pivot_calculation(chunk_to_sort, split_chunks);

	// Iterate through the chunk to be split
		WHILE i less than or equal to chunk_to_sort.max:
		{
			/*
			 * The chunk will have its value moved to BOTTOM_A, TOP_B, BOTTOM_B
			 	accordly with the range from min, pivot1, pivot2, max.
			 * If the chunk is located on stack B it must be moved back to stack A
				to be splited from there(it could be split from stack B but for 
				simplicity keeps it from stack A)
			 * The base case to stop the split is size of chunk less or = to 3
			 */
		}
		ENDWHILE
}

// MERGE BACK AND SORT FUNCTION
void	merge_back_and_sort(void chunk_to_sort, void split_chunks, void list_program)
{
	// Simple sort of the chunk that is in the Stack A
		selection_sort_chunk(list_program);

	// Move elements from mid chunk (in stack B) back to stack A.
		WHILE
		{
			push from B to A ("pa");
		}

	// Create a new chunk on stack A based on the mid chunk
		IF chunk_to_sort_new.size > 3
		{
			// Recursive split
			recursive_split_chunk(chunk_to_sort_new, list_program);
			// Simple sort
			selection_sort_chunk(list_program)
		}

	// Move elements from min chunk (originally at the bottom of B) back to stack A.
		WHILE (i > 0 AND stack B is not empty)
		{
			rotate reverse ("rr")  // This moves elements from bottom of B to top
			push from B to A ("pa")
		}

	// Create a new chunk on stack A based on the min chunk
		IF split_chunks.min.size > 3
		{
			recursive_split_chunk(chunk_to_sort_new, list_program)
			//simple sort
			selection_sort_chunk(list_program)
		}
}

// PIVOT CALCULATION FUNCTION
void pivot_calculation(void chunk_to_sort, void split_chunks)
{
	/* 
	* Perform calculations to determine pivot values and chunk boundaries.
	* pivot1 and pivot2 are calculated based on the values in the chunk to sort.
	* The chunk is then split into three sub-chunks based on these pivot values.
	* The pivot values are used to determine the boundaries of the sub-chunks.
	*/
}


// HELPERS
void is_sorted_linked_list_push(list_program);
void printer_dbg_split(split_chunks, list_program);
void selection_sort_chunk(list_program);
void push(stack, list_program);
void rotate(stack, stack_to_rotate, list_program);
void swap(stack, stack_to_rotate, list_program);