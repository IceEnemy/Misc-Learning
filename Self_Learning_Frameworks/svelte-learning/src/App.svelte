<script>
	const name = 'world';
	const channel = '<b>Codevolution</b>';
	const headingId = 'heading'
	const disabled = false;
	const status = 'success';
	const promoted = true;
</script>

<main>
	<h2 class="underline">Underlined Text</h2>
	<h2 class={status}>Status Text</h2>
	<h2 class:promoted>Movie Title</h2>
	<h1>Hello {name}</h1>
	<p>Subscribe to {@html channel}</p>

	<h2 id={headingId}>Heading 2</h2>
	<button disabled={disabled}>Click me</button>
</main>

<style>
	.underline{
		text-decoration: underline;
	}

	.danger {
		color: red;
	}

	.success {
		color: green;
	}

	.promoted{
		font-style: italic;
	}

	main {
		text-align: center;
		padding: 1em;
		max-width: 240px; 
		margin: 0 auto;
	}

	h1 {
		color: #ff3e00;
		text-transform: uppercase;
		font-size: 4em;
		font-weight: 100;
	}

	@media (min-width: 640px) {
		main {
			max-width: none;
		}
	}
</style>