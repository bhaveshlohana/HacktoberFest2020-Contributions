setInterval(() => {
    date = new Date();

    htime = date.getHours();
    mtime = date.getMinutes();
    stime = date.getSeconds();

    hrotate = 30*htime + mtime/2;
    mrotate = 6*mtime + 0.1*stime;
    srotate = 6*stime;

    hour.style.transform = `rotate(${hrotate}deg)`;
    minute.style.transform = `rotate(${mrotate}deg)`;
    second.style.transform = `rotate(${srotate}deg)`;

}, 1000);