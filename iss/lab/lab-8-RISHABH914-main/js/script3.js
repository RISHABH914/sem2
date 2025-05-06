  // Select DOM elements
  const gameContainer = document.getElementById('game-container');
  const resetButton = document.getElementById('reset-button');
  const startButton = document.getElementById('start-button'); // Added start button
  const difficultySlider = document.getElementById('difficulty');
  const movesDisplay = document.getElementById('moves');
  const timerDisplay = document.getElementById('timer');

  // Game variables
  let gridSize = parseInt(difficultySlider.value); // Grid size (e.g., 4x4)
  let cards = [];
  let flippedCards = [];
  let matchedPairs = 0;
  let moves = 0;
  let timer = 0;
  let timerInterval;
  let gameStarted = false; // Track if the game has started

  // Initialize the game
  function initGame() {
    clearInterval(timerInterval); // Reset the timer
    timer = 0;
    moves = 0;
    matchedPairs = 0;
    gameStarted = false; // Ensure game starts only when clicked

    movesDisplay.textContent = `Moves: ${moves}`;
    timerDisplay.textContent = `Time: ${timer}s`;
    gameContainer.innerHTML = ''; // Clear the board
    gridSize = parseInt(difficultySlider.value); // Update grid size

    generateCards();
    renderBoard();
  }

  // Generate cards with matching pairs
  function generateCards() {
    const totalCards = (gridSize * gridSize) / 2; // Half the grid size
    const symbols = Array.from({ length: totalCards }, (_, i) => String.fromCharCode(65 + i)); // A, B, C...
    cards = [...symbols, ...symbols]; // Duplicate symbols for pairs
    shuffleArray(cards);
  }

  // Shuffle the array of cards
  function shuffleArray(array) {
    for (let i = array.length - 1; i > 0; i--) {
      const j = Math.floor(Math.random() * (i + 1));
      [array[i], array[j]] = [array[j], array[i]];
    }
  }

  // Render the game board
  function renderBoard() {
    gameContainer.style.gridTemplateColumns = `repeat(${gridSize}, 80px)`; // Adjust grid size
    cards.forEach((symbol, index) => {
      const card = document.createElement('div');
      card.classList.add('card');
      card.dataset.symbol = symbol;
      card.addEventListener('click', () => flipCard(card));
      gameContainer.appendChild(card);
    });
  }

  // Flip a card
  function flipCard(card) {
    if (!gameStarted) {
      startTimer();
      gameStarted = true;
    }

    if (flippedCards.length >= 2 || card.classList.contains('flipped')) return; // Limit to 2 flips

    card.classList.add('flipped');
    card.textContent = card.dataset.symbol;
    flippedCards.push(card);

    moves++; // Increment moves
    movesDisplay.textContent = `Moves: ${moves}`;

    if (flippedCards.length === 2) {
      setTimeout(checkMatch, 500);
    }
  }

  // Check if the flipped cards match
  function checkMatch() {
    const [card1, card2] = flippedCards;

    if (card1.dataset.symbol === card2.dataset.symbol) {
      matchedPairs++;
      flippedCards = [];
    } else {
      setTimeout(() => {
        card1.classList.remove('flipped');
        card2.classList.remove('flipped');
        card1.textContent = '';
        card2.textContent = '';
        flippedCards = [];
      }, 1000);
    }

    if (matchedPairs === cards.length / 2) {
      clearInterval(timerInterval);
      alert(`Congratulations! You won in ${moves} moves and ${timer} seconds!`);
      initGame(); // Reset the grid after winning
    }
  }

  // Start the timer only when the first move is made
  //to prevent any lag from user side 
  function startTimer() {
    clearInterval(timerInterval);
    timer = 0;
    timerDisplay.textContent = `Time: ${timer}s`;
    timerInterval = setInterval(() => {
      timer++;
      timerDisplay.textContent = `Time: ${timer}s`;
    }, 1000);
  }

  resetButton.addEventListener('click', initGame);
  startButton.addEventListener('click', initGame); 
  difficultySlider.addEventListener('input', initGame);

