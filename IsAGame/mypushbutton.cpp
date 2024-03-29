#include "mypushbutton.h"
#include "QDebug"
#include "QPropertyAnimation"

MyPushButton::MyPushButton(QString normalImg,QString pressImg)
{
    this->normalImgPath=normalImg;
    this->pressImgPath = pressImg;

    QPixmap pix;
    bool ret = pix.load(normalImg);

    if(!ret)
    {
        qDebug()<<"图片加载失败";
        return;

    }
    //设置图片大小
    this->setFixedSize(pix.width(),pix.height());
    //设置不规则图片样式
    this->setStyleSheet("QPushButton{border:0px}");
    //设置图标
     this->setIcon(pix);
    //设置图标的大小
    this->setIconSize(QSize(pix.width(),pix.height()));




}

void MyPushButton::zoom1()
{
    //创建动画对象
    QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry");
    //设置动画间隔时间
    animation->setDuration(200);
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();

}

void MyPushButton::zoom2()
{
    //创建动画对象
    QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry");
    //设置动画间隔时间
    animation->setDuration(200);
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();

}


void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    if(this->pressImgPath !="")
    {
        QPixmap pix;
        bool ret = pix.load(this->pressImgPath);

        if(!ret)
        {
            qDebug()<<"图片加载失败";
            return;

        }
        //设置图片大小
        this->setFixedSize(pix.width(),pix.height());
        //设置不规则图片样式
        this->setStyleSheet("QPushButton{border:0px}");
        //设置图标
         this->setIcon(pix);
        //设置图标的大小
        this->setIconSize(QSize(pix.width(),pix.height()));


    }
        return QPushButton::mousePressEvent(e);
};
void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(this->pressImgPath !="")
    {
        QPixmap pix;
        bool ret = pix.load(this->normalImgPath);

        if(!ret)
        {
            qDebug()<<"图片加载失败";
            return;

        }
        //设置图片大小
        this->setFixedSize(pix.width(),pix.height());
        //设置不规则图片样式
        this->setStyleSheet("QPushButton{border:0px}");
        //设置图标
         this->setIcon(pix);
        //设置图标的大小
        this->setIconSize(QSize(pix.width(),pix.height()));

    }
        return QPushButton::mouseReleaseEvent(e);

};
