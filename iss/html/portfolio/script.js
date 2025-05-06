// Scroll Progress
const scrollProgress = document.querySelector('.scroll-progress');

window.addEventListener('scroll', () => {
    const scrollTop = document.documentElement.scrollTop || document.body.scrollTop;
    const scrollHeight = document.documentElement.scrollHeight - document.documentElement.clientHeight;
    const scrollPercentage = (scrollTop / scrollHeight) * 100;
    
    scrollProgress.style.width = scrollPercentage + '%';
    
    // Scroll to Top Button
    const scrollToTop = document.querySelector('.scroll-to-top');
    if (scrollTop > 300) {
        scrollToTop.classList.add('visible');
    } else {
        scrollToTop.classList.remove('visible');
    }
    
    // Animate elements on scroll
    const animateElements = (elements, className) => {
        elements.forEach(element => {
            const elementPosition = element.getBoundingClientRect().top;
            const screenPosition = window.innerHeight / 1.2;
            
            if (elementPosition < screenPosition) {
                element.classList.add(className);
            }
        });
    };
    
    animateElements(document.querySelectorAll('.about-text, .contact-info'), 'animated');
    animateElements(document.querySelectorAll('.about-image, .contact-form'), 'animated');
    animateElements(document.querySelectorAll('.stat-item'), 'animated');
    animateElements(document.querySelectorAll('.project-card'), 'animated');
    animateElements(document.querySelectorAll('.achievement-card'), 'animated');
});

// Scroll to Top
document.querySelector('.scroll-to-top').addEventListener('click', () => {
    window.scrollTo({
        top: 0,
        behavior: 'smooth'
    });
});

// Smooth Scroll for Navigation
document.querySelectorAll('a[href^="#"]').forEach(anchor => {
    anchor.addEventListener('click', function(e) {
        e.preventDefault();
        
        const targetId = this.getAttribute('href');
        const targetElement = document.querySelector(targetId);
        
        window.scrollTo({
            top: targetElement.offsetTop - 70,
            behavior: 'smooth'
        });
    });
});

// Trigger animations for elements visible on page load
window.addEventListener('load', () => {
    window.dispatchEvent(new Event('scroll'));
});

// Event Tracking System
function trackUserInteractions() {
    // Implementation of the event tracking system
    // ... (include the entire trackUserInteractions function here)
}

// Initialize tracking system when the DOM is fully loaded
document.addEventListener('DOMContentLoaded', function() {
    trackUserInteractions();
    console.log('Event tracking system initialized');
});
