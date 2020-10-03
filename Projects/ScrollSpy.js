import React, { Component, Profiler } from 'react'

export default class ScrollSpy extends Component {
    constructor(){
        super()
        this.state = {
            profile: 'white',
            skills: '#8da1a8',
            xp: '#8da1a8',
        }
    }
    componentDidMount(){
        let skills = document.querySelector('#skills');
        let xp = document.querySelector('#xp');
        let profile = document.querySelector('#profile');
        
        window.addEventListener('scroll', ()=>{
            let windo = window.pageYOffset;
            if( skills.offsetTop > windo ){
                this.setState({
                    profile:'white',
                    skills: '#8da1a8',
                    xp: '#8da1a8'
                })
            }
            else if(skills.offsetTop <= windo && xp.offsetTop > windo ){
                this.setState({
                    profile: '#8da1a8',
                    skills: 'white',
                    xp: '#8da1a8',
                })
            }
            else{
                this.setState({
                    profile: '#8da1a8',
                    skills: '#8da1a8',
                    xp: 'white',
                })
            }
        })
    }
    render() {
        return (
            <div className="scrollspy">
                    <a style={{color: this.state.profile}} href='#profile' className='profile'>PROFILE</a>
                    <a style={{color: this.state.skills}} href='#skills' className='skills'>SKILLS</a>
                    <a style={{color: this.state.xp}} href='#xp' className='xp'>EXPERIENCE</a>
            </div>
        )
    }
}
