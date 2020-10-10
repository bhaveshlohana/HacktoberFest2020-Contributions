class HelloWorld extends HTMLElement {
    constructor() {
      super();
      this._tooltipContainer;
      this._tooltipText = 'Hello World';
    }
  
    connectedCallback() {
      const tooltipIcon = document.createElement('span');
      tooltipIcon.textContent = 'Please hover here to display the helloworld';
      tooltipIcon.addEventListener('mouseenter', this._showTooltip.bind(this));
      tooltipIcon.addEventListener('mouseleave', this._hideTooltip.bind(this));
      this.appendChild(tooltipIcon);
    }
  
    _showTooltip() {
      this._tooltipContainer = document.createElement('div');
      this._tooltipContainer.textContent = this._tooltipText;
      this.appendChild(this._tooltipContainer);
    }
  
    _hideTooltip() {
      this.removeChild(this._tooltipContainer);
    }
  }
  
  customElements.define('wc-helloworld', HelloWorld);
  